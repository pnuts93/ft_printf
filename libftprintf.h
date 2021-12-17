/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:48:03 by pnuti             #+#    #+#             */
/*   Updated: 2021/06/13 18:05:49 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_args
{
	va_list	ap;
	size_t	i;
	int		dash;
	int		n_buff;
	int		abs_width;
	int		dot;
	int		prec;
	size_t	arglen;
	size_t	count;
}	t_args;
void	get_arg(const char *s, t_args *args);
void	put_buff(t_args *args, size_t n, int c);
void	p_char(t_args *args);
void	p_str(t_args *args);
void	p_int(t_args *args);
void	p_mem(t_args *args);
void	p_uns(t_args *args);
void	p_hex(const char *s, t_args *args);
void	p_nul(t_args *args);
void	p_nint(t_args *args, char *n);
int		ft_printf(const char *s, ...);
void	proc_nbrs(t_args *args, char *n);

#endif