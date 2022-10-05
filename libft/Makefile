#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okoponen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 17:35:36 by okoponen          #+#    #+#              #
#    Updated: 2022/08/31 17:35:37 by okoponen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME		= libft.a
HEADER		= libft.h
FLAGS		= -Wall -Werror -Wextra -I

DEF_COLOR = \033[0;39m
RED = \033[1;91m
GREEN = \033[1;92m

FILES = ft_atoi
FILES += ft_bzero
FILES += ft_isalnum
FILES += ft_isalpha
FILES += ft_isascii
FILES += ft_isdigit
FILES += ft_isprint
FILES += ft_memccpy
FILES += ft_memchr
FILES += ft_memcmp
FILES += ft_memcpy
FILES += ft_memmove
FILES += ft_memset
FILES += ft_strcat
FILES += ft_strchr
FILES += ft_strcmp
FILES += ft_strcpy
FILES += ft_strdup
FILES += ft_strlcat
FILES += ft_strlen
FILES += ft_strncat
FILES += ft_strncmp
FILES += ft_strncpy
FILES += ft_strnstr
FILES += ft_strstr
FILES += ft_tolower
FILES += ft_toupper
FILES += ft_strrchr
FILES += ft_memalloc
FILES += ft_memdel
FILES += ft_strnew
FILES += ft_strdel
FILES += ft_strclr
FILES += ft_striter
FILES += ft_striteri
FILES += ft_strmap
FILES += ft_strmapi
FILES += ft_strequ
FILES += ft_strnequ
FILES += ft_strsub
FILES += ft_strjoin
FILES += ft_strtrim
FILES += ft_strsplit
FILES += ft_itoa
FILES += ft_strrev
FILES += ft_swap
FILES += ft_putchar
FILES += ft_putstr
FILES += ft_putendl
FILES += ft_putnbr
FILES += ft_putchar_fd
FILES += ft_putstr_fd
FILES += ft_putendl_fd
FILES += ft_putnbr_fd
FILES += ft_isupper
FILES += ft_islower
FILES += ft_lstnew
FILES += ft_lstdelone
FILES += ft_iswhitespace
FILES += ft_itoa_base
FILES += ft_itoa_base_lower

FILE	= $(addsuffix .c, $(FILES))
OBJ		= $(addsuffix .o, $(FILES))

all: $(NAME)
$(NAME): $(FILE)
	@gcc $(FLAGS) $(HEADER) -c $(FILE)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)LIBFT Complete$(DEF_COLOR)"

clean:
	@/bin/rm -f $(OBJ)
	@echo "$(RED)OBJ Files Cleaned$(DEF_COLOR)"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(RED)LIBFT Cleaned$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re