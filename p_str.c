/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 10:34:05 by pnuti             #+#    #+#             */
/*   Updated: 2021/06/13 18:09:53 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	p_str(t_args *args)
{
	char	*s;
	size_t	slen;

	s = va_arg(args->ap, char *);
	if (!s)
	{
		p_nul(args);
		return ;
	}
	slen = ft_strlen(s);
	if (args->dot == 1)
		args->arglen = ft_subtilzero(args->abs_width, ft_min(slen, args->prec));
	else
		args->arglen = ft_subtilzero(args->abs_width, slen);
	if (args->dash == 0)
		put_buff(args, args->arglen, ' ');
	if (args->dot == 1 && args->prec < (int)slen)
		args->count += write(1, s, args->prec);
	else
		args->count += write(1, s, slen);
	if (args->dash == 1)
		put_buff(args, args->arglen, ' ');
}
