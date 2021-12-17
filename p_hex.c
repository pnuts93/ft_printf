/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:13:17 by pnuti             #+#    #+#             */
/*   Updated: 2021/06/13 18:07:42 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	p_hex(const char *s, t_args *args)
{
	char	*hex;
	size_t	i;

	hex = ft_tohex(va_arg(args->ap, int));
	i = 0;
	if (s[args->i] == 'X')
		ft_allcaps(hex);
	while (hex[i] == '0' && hex[i + 1] != '\0')
		i++;
	proc_nbrs(args, &hex[i]);
	free(hex);
}
