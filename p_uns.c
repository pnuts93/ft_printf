/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_uns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:15:00 by pnuti             #+#    #+#             */
/*   Updated: 2021/06/13 18:11:36 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	p_uns(t_args *args)
{
	char	*n;

	n = ft_utoa(va_arg(args->ap, unsigned int));
	proc_nbrs(args, n);
	free(n);
}
