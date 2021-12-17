/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:35:11 by pnuti             #+#    #+#             */
/*   Updated: 2021/06/13 18:06:21 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	p_char(t_args *args)
{
	char	c;

	c = va_arg(args->ap, int);
	if (args->abs_width > 0)
		args->arglen = args->abs_width - 1;
	if (args->dash == 0)
		put_buff(args, args->arglen, ' ');
	args->count += write(1, &c, 1);
	if (args->dash == 1)
		put_buff(args, args->arglen, ' ');
}
