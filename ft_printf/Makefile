# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-matt <gde-matt@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/18 15:41:42 by gde-matt          #+#    #+#              #
#    Updated: 2020/12/21 21:13:41 by gde-matt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = src/*.c

OBJECTS = *.o

LIB = ft_printf.h

all: $(NAME)

$(NAME): $(OBJECTS)

$(OBJECTS) : $(SRCS) $(LIB)
	@gcc -Wextra -Werror -Wall -c -g -I . $(LIB) $(SRCS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf *.gch

re: fclean all
