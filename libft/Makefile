# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atuomine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 13:38:08 by atuomine          #+#    #+#              #
#    Updated: 2020/01/24 11:56:54 by atuomine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INC = includes
SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
	  ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
	  ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	  ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
	  ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
	  ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
	  ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
	  ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
	  ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	  ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
	  ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
	  ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
	  ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
	  ft_lstadd.c ft_lstnew.c ft_atoll.c get_next_line.c \
	ft_isnum.c
OBJECT = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o \
	  ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o \
	  ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o \
	  ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o \
	  ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o \
	  ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o \
	  ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o \
	  ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o \
	  ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o \
	  ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o \
	  ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o \
	  ft_strnstr.o ft_strrchr.o ft_strsplit.o ft_strstr.o \
	  ft_strsub.o ft_strtrim.o ft_tolower.o ft_toupper.o \
	  ft_lstadd.o ft_lstnew.o ft_atoll.o get_next_line.o \
	  ft_isnum.o
SRC2 = ft_printf/addr.c ft_printf/base.c ft_printf/char_and_string.c \
	   ft_printf/conversion.c ft_printf/decimal.c ft_printf/decimal_long.c \
	   ft_printf/extraprints.c ft_printf/float.c ft_printf/float_long.c \
	  ft_printf/ft_atox.c ft_printf/ft_llutoa.c ft_printf/ft_nbr.c \
	  ft_printf/ft_printf.c ft_printf/ft_put.c ft_printf/identifier.c \
	  ft_printf/identifier_checks.c ft_printf/integer.c \
	  ft_printf/wildcard.c ft_printf/unprintable.c ft_printf/ft_putchar_nonprint.c \
	  ft_printf/ft_putstr_nonprint.c ft_printf/ft_strlenint.c
OBJECT2 = addr.o base.o char_and_string.o conversion.o \
		  decimal.o decimal_long.o extraprints.o float.o float_long.o \
	  ft_atox.o ft_llutoa.o ft_nbr.o ft_printf.o ft_put.o identifier.o \
	  identifier_checks.o integer.o \
	  wildcard.o unprintable.o ft_putchar_nonprint.o ft_putstr_nonprint.o \
	  ft_strlenint.o

all: $(NAME)

$(NAME):
			gcc -I $(INC) -c $(SRC) $(SRC2)
			ar rc $(NAME) $(OBJECT) $(OBJECT2)
			ranlib $(NAME)

clean:
			/bin/rm -f $(OBJECT) $(OBJECT2)

fclean:		clean
			/bin/rm -f $(NAME)

re:			fclean all
