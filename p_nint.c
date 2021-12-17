/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_nint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:10:27 by pnuti             #+#    #+#             */
/*   Updated: 2021/06/13 18:09:08 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	p_nint(t_args *args, char *n)
{
	size_t	len;
	size_t	zeros;

	len = ft_strlen(n);
	zeros = ft_subtilzero(args->prec, len - 1);
	if (args->dot == 1)
		args->n_buff = ' ';
	args->arglen = ft_subtilzero(args->abs_width, ft_max(len, args->prec + 1));
	if (args->dot == 0 && args->n_buff == '0')
		args->count += write(1, "-", 1);
	if (args->dash == 0)
		put_buff(args, args->arglen, args->n_buff);
	if (args->dot == 1 || args->n_buff != '0')
		args->count += write(1, "-", 1);
	put_buff(args, zeros, '0');
	args->count += write(1, &n[1], len - 1);
	free(n);
	if (args->dash == 1)
		put_buff(args, args->arglen, ' ');
}
