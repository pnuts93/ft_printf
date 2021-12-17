/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:14:48 by pnuti             #+#    #+#             */
/*   Updated: 2021/06/13 18:23:27 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	get_width(const char *s, t_args *args)
{
	if (ft_isdigit(s[args->i]))
	{
		args->abs_width = ft_atoi(&s[args->i]);
		while (ft_isdigit(s[args->i]))
			args->i++;
	}
	else if (s[args->i] == '*')
	{
		args->abs_width = va_arg(args->ap, int);
		while (s[args->i] == '*')
			args->i++;
	}
	if (args->abs_width < 0)
	{
		args->abs_width *= -1;
		args->dash = 1;
	}
}

static void	get_prec(const char *s, t_args *args)
{
	if (ft_isdigit(s[args->i]))
	{
		args->prec = ft_atoi(&s[args->i]);
		while (ft_isdigit(s[args->i]))
			args->i++;
	}
	else if (s[args->i] == '*')
	{
		args->prec = va_arg(args->ap, int);
		while (s[args->i] == '*')
			args->i++;
	}
	if (args->prec < 0)
	{
		args->dot = 0;
		args->prec = 0;
	}
}

static void	get_flag(const char *s, t_args *args)
{
	if (s[args->i] == 'c')
		p_char(args);
	else if (s[args->i] == 's')
		p_str(args);
	else if (s[args->i] == 'd' || s[args->i] == 'i')
		p_int(args);
	else if (s[args->i] == 'p')
		p_mem(args);
	else if (s[args->i] == 'u')
		p_uns(args);
	else if (ft_tolower(s[args->i]) == 'x')
		p_hex(s, args);
	else if (s[args->i] == '%')
		args->count += write(1, "%%", 1);
}

void	get_arg(const char *s, t_args *args)
{
	if (s[args->i] == '-')
	{
		args->dash = 1;
		while (s[args->i] == '-')
			args->i++;
	}
	if (s[args->i] == '0')
	{
		args->n_buff = '0';
		while (s[args->i] == '0')
			args->i++;
	}
	if (ft_isdigit(s[args->i]) || s[args->i] == '*')
		get_width(s, args);
	if (s[args->i] == '.')
	{
		args->dot = 1;
		while (s[args->i] == '.')
			args->i++;
	}
	if (ft_isdigit(s[args->i]) || s[args->i] == '*')
		get_prec(s, args);
	get_flag(s, args);
}
