/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 10:43:35 by pnuti             #+#    #+#             */
/*   Updated: 2021/06/13 18:08:02 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	p_int(t_args *args)
{
	char		*n;

	n = ft_itoa(va_arg(args->ap, int));
	if (n[0] == '-')
	{
		p_nint(args, n);
		return ;
	}
	proc_nbrs(args, n);
	free(n);
}
