# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atuomine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 13:38:08 by atuomine          #+#    #+#              #
#    Updated: 2020/01/24 11:57:56 by atuomine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
INC = libft/includes
SRC = main.c parse_arguments.c sort_entries.c
OBJECT = $(SRC:%.c=%.o)
LIBRARY = libft/libft.a

all: $(NAME)

$(LIBRARY):
			make -C libft/

$(NAME):	$(LIBRARY)
			gcc -I $(INC) -c $(SRC)
			gcc $(OBJECT) $(LIBRARY) -o $(NAME)

clean:
			/bin/rm -f $(OBJECT)
			make -C libft/ clean

fclean:		clean
			/bin/rm -f $(NAME)
			#make -C libft/ fclean

re:			fclean all

.PHONY: 	all clean fclean re
