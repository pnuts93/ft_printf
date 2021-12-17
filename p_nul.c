/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_nul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:47:16 by pnuti             #+#    #+#             */
/*   Updated: 2021/06/13 18:09:29 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	p_nul(t_args *args)
{
	size_t	len;

	len = 6;
	if (args->dot == 1 && args->prec < (int)len)
	{
		args->arglen = args->abs_width;
		len = 0;
	}
	else
		args->arglen = ft_subtilzero(args->abs_width, len);
	if (args->dash == 0)
		put_buff(args, args->arglen, ' ');
	if (args->dot == 1)
		args->count += write(1, "(null)", (size_t)ft_min(len, args->prec));
	else
		args->count += write(1, "(null)", len);
	if (args->dash == 1)
		put_buff(args, args->arglen, ' ');
}
