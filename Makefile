# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obraiki <obraiki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 12:46:13 by obraiki           #+#    #+#              #
#    Updated: 2021/12/08 11:06:55 by obraiki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJ = ft_printf.o \
	  ft_printf_utils.o \

all : $(NAME)

$(NAME) : $(OBJ)
		@ ar -rcs $(NAME) $(OBJ)
		
%.o : %.c ft_printf.h
		$(CC) $(FLAGS) -c $< -o $@

clean : 
	@ rm -f $(OBJ)

fclean : clean
	@ rm -f $(NAME)
	
re : fclean all