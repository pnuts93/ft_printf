/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_buff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 10:21:19 by pnuti             #+#    #+#             */
/*   Updated: 2021/06/13 18:11:57 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	put_buff(t_args *args, size_t n, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (n > 0)
	{
		args->count += write(1, &uc, 1);
		n--;
	}
}
