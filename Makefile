# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elias <elias@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 16:41:15 by eliagarc          #+#    #+#              #
#    Updated: 2024/01/02 00:52:35 by elias            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

SOURCE =  ft_printf.c	ft_putstrchr.c 	ft_checks.c \
ft_putnumbers.c ft_putpointer.c ft_puthexa.c
INCLUDE = ft_printf.h 

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJS = $(SOURCE:.c=.o)

%.o:%.c $(INCLUDE)
	@echo "Compiling $<..."
	@${CC} -c ${CFLAGS} -I ${INCLUDE} $< -o $@

$(NAME): ${OBJS} $(INCLUDE) Makefile
	@echo "Creating library..."
	@ar rc ${NAME} ${OBJS}
	@echo "$(COLOUR_GREEN)Done!$(COLOUR_END)"

all: $(NAME)

clean:
	@echo "$(COLOUR_RED)Cleaning object files...$(COLOUR_END)"
	@rm -f $(OBJS)

fclean:	clean
	@echo "$(COLOUR_RED)Cleaning all trash...$(COLOUR_END)"
	@rm -f $(NAME)

re: 	fclean all

.PHONY: all clean fclean re