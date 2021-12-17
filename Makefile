# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 14:40:41 by pnuti             #+#    #+#              #
#    Updated: 2021/12/17 14:59:35 by pnuti            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER	=	libftprintf.h
NAME	=	libftprintf.a
FLAGS	=	-Wall -Werror -Wextra
OBJ		=	ft_printf.o	get_arg.o	p_char.o	p_hex.o		\
			p_int.o		p_mem.o		p_str.o		p_uns.o		\
			put_buff.o	p_nul.o		p_nint.o	proc_nbrs.o

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $@ $^ libft/*.o
%.o : %.c $(HEADER) makelibft
	$(CC) -c $(FLAGS) -o $@ $<
makelibft: download_lib
	cd libft && make && make bonus
download_lib:
	git clone https://github.com/pnuts93/libft.git
fclean : clean
	rm -fr libft
	rm -f $(NAME)
clean :
	rm -f $(OBJ)
re : fclean all
