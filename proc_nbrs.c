/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_nbrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:18:23 by pnuti             #+#    #+#             */
/*   Updated: 2021/06/13 18:11:45 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	proc_nbrs(t_args *args, char *n)
{
	size_t	len;
	size_t	zeros;

	len = ft_strlen(n);
	zeros = ft_subtilzero(args->prec, len);
	if (args->dot == 1)
		args->n_buff = ' ';
	args->arglen = ft_subtilzero(args->abs_width, ft_max(len, args->prec));
	if (args->dash == 0)
		put_buff(args, args->arglen, args->n_buff);
	put_buff(args, zeros, '0');
	if (args->dot == 1 && args->prec == 0 && n[0] == '0')
	{
		if (args->abs_width > 0)
			args->count += write(1, " ", 1);
	}
	else
		args->count += write(1, n, len);
	if (args->dash == 1)
		put_buff(args, args->arglen, ' ');
}
