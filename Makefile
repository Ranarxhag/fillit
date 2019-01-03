# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjovanov <bjovanov@student.19.be>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/03 21:55:10 by bjovanov          #+#    #+#              #
#    Updated: 2018/11/01 17:48:42 by bjovanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c fillit.c file_checker.c resolver.c map.c tetriminos.c positions.c
INC = .
OBJ = $(subst .c,.o,$(SRC))
NAME = fillit

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@gcc -Wall -Wextra -Werror -c $(SRC) -I $(INC)
	@gcc -Wall -Wextra -Werror $(OBJ) -I $(INC) -L libft/ -lft -o $(NAME)
	@echo "Compilation des fichiers sources...OK"

clean:
	@rm -rf $(OBJ)
	@make -C libft/ clean
	@echo "Suppression des fichiers objets...OK"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ fclean
	@echo "Suppression du fichier $(NAME)...OK"

re: fclean all
