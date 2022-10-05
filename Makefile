#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okoponen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 16:11:45 by okoponen          #+#    #+#              #
#    Updated: 2022/09/21 14:15:55 by okoponen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 	= okoponen.filler
LIBFT 	= ./libft
FLAGS   = -Wall -Wextra -Werror
SRC_DIR = srcs/

DEF_COLOR = \033[0;39m
RED = \033[1;91m
GREEN = \033[1;92m

SRC_FILES = filler
SRC_FILES += get_next_line
SRC_FILES += heatmap
SRC_FILES += place_piece
SRC_FILES += helper_functions

SRC	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ	= $(addsuffix .o, $(SRC_FILES))

.PHONY : all clean fclean re ft_printf

all : $(NAME)

$(NAME) : $(SRC)
	@ make -C $(LIBFT)
	@ gcc $(FLAGS) -c $(SRC)
	@ gcc -o $(NAME) -Llibft -lft $(OBJ)
	@echo "$(GREEN)Filler Complete$(DEF_COLOR)"

clean :
	@ rm -f $(OBJ)
	@ make clean -C libft/

fclean : clean
	@ rm -f $(NAME)
	@ rm -f $(OBJ)
	@ make fclean -C libft/

re : fclean all
