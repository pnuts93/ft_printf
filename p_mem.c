/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_mem.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 11:46:34 by pnuti             #+#    #+#             */
/*   Updated: 2021/06/16 09:33:51 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	putdig(unsigned long long addr, char *s, int i, unsigned int *j)
{
	char	*hbase;

	hbase = "0123456789abcdef";
	if (!addr)
	{
		if (i == 0)
			s[*j] = '0';
		return ;
	}
	putdig(addr >> 4, s, i + 1, j);
	s[*j] = hbase[addr % 16];
	(*j)++;
}

static size_t	len_mem(unsigned long long addr)
{
	size_t	i;

	i = 3;
	while (addr)
	{
		addr = addr >> 4;
		i++;
	}
	return (i);
}

void	p_mem(t_args *args)
{
	unsigned long long		p;
	char					*s;
	unsigned int			j;
	size_t					mlen;

	p = va_arg(args->ap, unsigned long long);
	s = (char *)ft_calloc(len_mem(p), sizeof(char));
	if (!s)
		return ;
	s[0] = '0';
	s[1] = 'x';
	j = 2;
	putdig(p, s, 0, &j);
	mlen = ft_strlen(s);
	args->arglen = ft_subtilzero(args->abs_width, mlen);
	if (args->dash == 0)
		put_buff(args, args->arglen, ' ');
	args->count += write(1, s, mlen);
	if (args->dash == 1)
		put_buff(args, args->arglen, ' ');
	free(s);
}
