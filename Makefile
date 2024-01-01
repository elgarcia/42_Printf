# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eliagarc <eliagarc@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 16:41:15 by eliagarc          #+#    #+#              #
#    Updated: 2023/09/20 16:41:16 by eliagarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCE =  ft_printf.c	ft_putstrchr.c 	ft_checks.c \
ft_putnumbers.c ft_putpointer.c ft_puthexa.c
INCLUDE = ft_printf.h 

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJS = $(SOURCE:.c=.o)

%.o:%.c $(INCLUDE)
	${CC} -c ${CFLAGS} -I ${INCLUDE} $< -o $@

$(NAME): ${OBJS} $(INCLUDE) Makefile
	ar rc ${NAME} ${OBJS}

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all

.PHONY: all clean fclean re