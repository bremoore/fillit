# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaluko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 11:08:25 by aaluko            #+#    #+#              #
#    Updated: 2019/04/11 14:48:10 by aaluko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

cc = gcc

FLAGS = -Wall -Wextra -Werror -c

SRCS = ./*.c
OBJECTS = ./*.o
INCLUDES = libft.h

all: $(NAME)
$(NAME): $(SRCS) $(INCLUDES)
	$(CC) $(FLAGS) $(SRCS) -I $(INCLUDES)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all
