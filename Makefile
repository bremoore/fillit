# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaluko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/18 16:57:08 by aaluko            #+#    #+#              #
#    Updated: 2019/04/22 16:22:19 by aaluko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= fillit
CC:= gcc
CFLAGS:= -Wall -Werror -Wextra
LIBFT:= ./libft/
INCLUDES:= ./s_fillit/*.h
SRCS:= ./s_fillit/*.c

all: $(NAME)
	
$(NAME): $(SRCS) $(INCLUDES)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT)libft.a -o $(NAME) $(SRCS) 

clean:
	rm -f *.o
	cd $(LIBFT) && make clean 

fclean: clean 
		rm -f $(NAME)
		cd $(LIBFT) && make fclean

re: fclean all
