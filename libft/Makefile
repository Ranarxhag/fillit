# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjovanov <bjovanov@student.19.be>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/03 21:55:10 by bjovanov          #+#    #+#              #
#    Updated: 2018/10/31 18:18:02 by bjovanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c ft_bzero.c ft_error.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c ft_itoa.c \
		ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
		ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
		ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
		ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
		ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
		ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
		ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_strclen.c ft_strstrsplit.c \
		ft_strreplace.c ft_array_length.c ft_sqrt.c
INC = .
OBJ = $(subst .c,.o,$(SRC));

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC) -I $(INC)
	@echo "Compilation des fichiers sources...OK"
	@ar rc $(NAME) $(OBJ)
	@echo "Création de la librairie...OK"
	@ranlib $(NAME)
	@echo "Indexation de la librairie...OK"

clean:
	@rm -rf $(OBJ)
	@echo "Suppression des fichiers objets...OK"

fclean: clean
	@rm -rf $(NAME)
	@echo "Suppression du fichier $(NAME)...OK"

re: fclean all
