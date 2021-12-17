/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:56:40 by pnuti             #+#    #+#             */
/*   Updated: 2021/12/17 14:24:27 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	init_args(t_args *args)
{
	args->dash = 0;
	args->n_buff = ' ';
	args->abs_width = 0;
	args->dot = 0;
	args->prec = 0;
	args->arglen = 0;
}

static void	process_src(const char *s, t_args *args)
{
	while (s[args->i])
	{
		if (s[args->i] == '%')
		{
			(args->i)++;
			if (s[args->i] != '%')
			{
				get_arg(s, args);
				init_args(args);
			}
			else
				args->count += write(1, "%%", 1);
		}
		else
		{
			ft_putchar_fd(s[args->i], 1);
			(args->count)++;
		}
		(args->i)++;
	}
}

int	ft_printf(const char *s, ...)
{
	t_args			args;

	if (!s)
		return (-1);
	args.i = 0;
	args.count = 0;
	init_args(&args);
	va_start(args.ap, s);
	process_src(s, &args);
	va_end(args.ap);
	return (args.count);
}
