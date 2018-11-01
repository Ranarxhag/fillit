/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <bjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:25:52 by bjovanov          #+#    #+#             */
/*   Updated: 2018/11/01 17:50:27 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Vérifie si le caractère passé en paramètre (str[i]) est au
** bon endroit et s'il ne contient que les caractères autorisés
** ('#', '.', '\'). Vérifie également que la ligne fait bien 4
** caractères ('.', '#') suivi d'un \n
**
** Retourne : '0' -> error | '1' -> success
*/
static int		is_valid_format(char *str, int i, int line_length)
{
	if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
		return (0);
	if (i == 0 && str[i] == '\n')
		return (0);
	if (i > 0 && i % 20 == 0 && line_length != 0)
		return (0);
	if (i > 0 && i % 20 == 0 && str[i] != '\n')
		return (0);	
	return (1);
}

/*
** Compte le nombre de '#' adjacent au '#' en cours de
** vérification (str[i]).
**
** Retourne : le nombre de '#' adjacents (result) 
*/
static int		count_adjacent_side(char *str, int i)
{
	int		result;
	size_t	str_len;

	str_len = ft_strlen(str);
	result = 0;
	if (i - 5 >= 0 && str[i - 5] == '#')
		result++;
	if ((size_t)i + 5 <= str_len && str[i + 5] == '#')
		result++;
	if (i - 1 >= 0 && str[i - 1] == '#')
		result++;
	if ((size_t)i + 1 <= str_len && str[i + 1] == '#')
		result++;
	return(result);
}

/*
** Vérifie si le tetriminos passé en paramètre à un format valide
** via is_valid_format() (4 * 4 caractères '.' ou '#' suivi de \n),
** compte son nombre de '#' pour vérifier s'il en possède 4 et compte
** le nombre de faces qui se touchent via count_adjacent_side() pour
** vérifier s'il y en a au minimum 6. Si ce n'est pas le cas, tous les
** '#' ne se touchent pas.
**
** Retourne : '0' -> error | '1' -> success
*/
static int		is_valid_tetriminos(char *str)
{
	int i;
	int line_length;
	int adjacent_side;
	int hashtag;

	i = 0;
	line_length = 0;
	adjacent_side = 0;
	hashtag = 0;
	while (str[i])
	{
		if (!is_valid_format(str, i, line_length))
			return (0);
		if (str[i] == '#')
		{
			hashtag++;
			adjacent_side += count_adjacent_side(str, i);
		}
		line_length = (str[i] == '\n' ? 0 : line_length + 1);
		i++;
	}
	if (hashtag != 4 || adjacent_side < 6 || (str[BUFF_SIZE - 2] != '\n' && str[BUFF_SIZE - 1] != '\n'))
		return (0);
	return (1);
}

/*
** Lit le fichier via son file descriptor par tranche de 21
** afin d'obtenir 1 à 1 les différents tetriminos et effectue
** toutes les vérifications nécessaire sur chacun de ces tetriminos
**
** Retourne : '0' -> error | '1' -> success
*/
int				read_file(int fd, char **str)
{
	char 	buff[BUFF_SIZE + 1];
	int		ret;
	int		old_ret;
	char	*temp;
	char	letter;

	*str = NULL;
	letter = 'A';
	while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (ret < BUFF_SIZE - 1 || !is_valid_tetriminos(buff))
			return (0);
		temp = *str == NULL ? ft_strdup("") : *str;
		ft_strreplace(buff, '#', letter);
		*str = ft_strjoin(temp, buff);
		old_ret = ret;
		ft_strdel(&temp);
		letter++;
	}
	if ((*str == NULL && ret == 0) || (ret == 0 && old_ret != 20))
		return (0);
	return (1);
}
