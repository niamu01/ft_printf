# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 10:48:17 by yeju              #+#    #+#              #
#    Updated: 2021/06/23 18:44:21 by yeju             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
LIBFT	= libft.a

SRCS	=./ft_printf.c \
		./ft_setting_tag.c \
		./print.c \
		./utils.c \
		./ft_manage_print.c \
		
OBJS	= ${SRCS:.c=.o}

RM		= rm -f
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra


%.o : %.c
	$(CC) $(CFLAGS) -I includes -o $@ -c $<

${NAME} : ${OBJS}
	make all -C libft/
	cp libft/${LIBFT} ${NAME}
	ar rcs ${NAME} ${OBJS}

all : ${NAME}

clean : 
	${RM} ${OBJS}
	make clean -C libft

fclean : clean
	${RM} ${NAME}
	make fclean -C libft

re : fclean all

.PHONY : clean fclean re