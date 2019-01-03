/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <bjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 14:50:40 by bjovanov          #+#    #+#             */
/*   Updated: 2018/11/09 11:24:21 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Fonction qui va vérifier si le tetriminos passé en paramètre à
** sa position actuelle peut être placé sur la map donc qu'il ne croise
** rien d'autre que des '.'
**
** Retourne : 1 si possible | 0 si impossible
*/

int		poscmp(char *map, char *tetriminos, int position, char letter)
{
	int i;

	i = 0;
	while (tetriminos[i])
	{
		if (tetriminos[i] == letter && map[i + position] != '.')
			return (0);
		i++;
	}
	return (1);
}

/*
** Fonction qui va créer le tableau de positions en fonction du nombre
** de tetriminos (en comptant le nombre de tetriminos dans **tab)
**
** Retourne : le tableau de positions si réussi | 0 si crash
*/

int		*set_positions(char **tab)
{
	int *positions;
	int	tab_length;
	int	i;

	i = 0;
	tab_length = ft_array_length((void**)tab);
	positions = (int*)malloc(sizeof(int) * tab_length);
	if (positions == NULL)
		return (0);
	while (i < tab_length)
	{
		positions[i] = 0;
		i++;
	}
	return (positions);
}

char	*replace_top_left(char *tab, char letter)
{
	char	*temp;
	char	*crop;
	size_t	tab_len;
	size_t	i;
	size_t	temp_len;

	if ((temp = set_map(4)) == NULL)
		return (NULL);
	if ((crop = remove_overflow(tab, letter)) == NULL)
	{
		ft_strdel(&temp);
		return (NULL);
	}
	i = -1;
	tab_len = ft_strlen(crop);
	temp_len = ft_strlen(temp);
	while (++i + tab_len <= temp_len)
	{
		if (poscmp(temp, crop, (int)i, letter) == 1)
		{
			write_map(temp, crop, (int)i, letter);
			break ;
		}
	}
	return (temp);
}
