/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <bjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 22:36:51 by bjovanov          #+#    #+#             */
/*   Updated: 2018/11/01 17:50:18 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Définit la taille de base de la map
** La taille de base est la plus petite taille possible en
** fonction du nombre de tetriminos qui doivent être agencés.
**
** Retourne : la racine carrée du nombre passé en paramètre
*/
int			set_map_size(int number)
{
	int sqrt;

	sqrt = 0;
	while (sqrt == 0)
	{
		sqrt = ft_sqrt(number);
		number++;
	}
	return (sqrt);
}

/*
** Fonction qui va écrire sur la map le tetriminos passé en paramètre
** (char *tetriminos) à partir de sa position de départ (position)
**/
static void	write_map(char *map, char *tetriminos, int position, char letter)
{
	int		i;

	i = 0;
	while (tetriminos[i])
	{
		if (tetriminos[i] == letter)
			map[i + position] = tetriminos[i];
		i++;
	}
}

/*
** Fonction appelée par fill_map() qui va vérifier si un élément peut être
** placé sur la map et si oui, va le placer (l'écrire) sur la map.
** 0. On supprime via ft_strreplace() le tetriminos s'il a déjà été placé
** Tant que le tetriminos peut être placé sur la map :
** 1. On vérifie si, en sa position, il ne chevauche pas un autre tetriminos
** 	  ou un \n. Si c'est le cas, il avance de 1 (position++) et on re-teste
** 2. S'il peut être placé, on le place sur la map via write_map() et
**    on retourne 1 afin que la fonction fill_map() passe au suivant
**
** Retourne : 1 si placé | 0 si impossible
*/
static int	is_placed(char **map, char **tetriminos, int *positions, int index)
{
	size_t	map_len;
	size_t	tetris_len;

	map_len = ft_strlen(*map);
	tetris_len = ft_strlen(tetriminos[index]);
	ft_strreplace(*map, 'A' + index, '.');
	while (((size_t)positions[index] + tetris_len) <= map_len)
	{
		if (poscmp(*map, tetriminos[index], positions[index], 'A' + index) == 1)
		{
			write_map(*map, tetriminos[index], positions[index], 'A' + index);
			positions[index]++;
			return (1);
		}
		positions[index]++;
	}
	positions[index] = 0;
	return (0);
}

/*
** Fonction appelée par can_be_resolved() qui va être la base du
** backtracking. On définit un tableau de positions ( set_positions() )
** qui va enregistrer les dernières positions de chaque tetriminos
** pendant l'agencement.
** On boucle sur chaque tetriminos et via la fonction is_placed(), on
** détermine si le tetriminos en cours est placé. S'il ne l'est pas, on
** revient un cran en arrière pour essayer de placer le tetriminos précédent
** sur une autre position. Si le premier tetriminos n'a pas réussi à être placé,
** cela signifie que la résolution sur une map de cette taille est impossible.
** Si le tetriminos en cours est placé, on passe au suivant.
**
** Retourne : 1 si la map a pu être remplie | 0 si résolution impossible
*/
int			fill_map(char **map, char **tetriminos)
{
	int	i;
	int *positions;
	int ret;

	i = 0;
	ret = 0;
	if((positions = set_positions(tetriminos)) == 0)
		return (-1);
	while(tetriminos[i])
	{
		if ((ret = is_placed(map, tetriminos, positions, i)) == 0)
		{
			if (i == 0)
			{
				free(positions);
				return (0);
			}
			i--;
			continue;
		}
		i++;
	}
	free(positions);
	return (1);
}

/*
** Crée la map de base en fonction du map_size passé en
** paramètre.
** La map est la zone sur laquelle vont être agencés les
** tetriminos.
**
** Retourne : la map (string) | NULL si erreur
*/
char		*set_map(int map_size)
{
	char	*map;
	int		area;
	int		i;

	i = 0;
	area = ((map_size + 1) * (map_size));
	if ((map = (char*)malloc(sizeof(char) * (area + 1))) == NULL)
		return (NULL);
	while (i < area)
	{
		if ((i + 1) % (map_size + 1) == 0)
			map[i] = '\n';
		else
			map[i] = '.';
		i++;
	}
	map[i] = '\0';
	return (map);
}
