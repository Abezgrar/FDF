# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/24 00:08:39 by abezgrar          #+#    #+#              #
#    Updated: 2017/11/24 00:08:54 by abezgrar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_NAME = main.c write_map.c trace_map.c fornorme.c menu.c

SRC_DIR = ./srcs/

INCL_DIR = includes

OBJ_DIR = ./obj/

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJ = $(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))

CFLAGS = -Wall -Wextra -Werror 

IFLAGS = -I./libft -I./minilibx_macos -I./$(INCL_DIR)

LFLAGS =  -L./libft -lft -framework OpenGL -framework AppKit -L./minilibx_macos -lmlx -lm 

all : $(NAME)

.PHONY : all clean

$(NAME) : $(OBJ)
	make -C ./libft/
	make -C ./minilibx_macos/
	gcc $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS) -c $(IFLAGS) $^ -o $@

norme :
	norminette $(SRC)
	norminette $(INCL_DIR)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)
	make clean -C libft/

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re:fclean all
