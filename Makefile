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

SRC = src/main.c src/fillit.c src/file_checker.c src/resolver.c src/map.c src/tetriminos.c src/positions.c
INC = ./inc
OBJ = $(subst .c,.o,$(SRC));
EXE = fillit

all: $(EXE)

$(EXE):
	@make -C libft/ fclean && make -C libft/ && make -C libft/ clean
	@gcc -Wall -Wextra -Werror $(SRC) -I $(INC) -L libft/ -lft -o $(EXE)
	@echo "Compilation des fichiers sources...OK"

clean:
	@rm -rf $(OBJ)
	@echo "Suppression des fichiers objets...OK"

fclean: clean
	@rm -rf $(EXE)
	@echo "Suppression du fichier $(EXE)...OK"

re: fclean all
