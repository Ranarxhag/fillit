/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <bjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 21:07:20 by bjovanov          #+#    #+#             */
/*   Updated: 2018/11/01 17:50:12 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Fonction en charge de supprimer le tableau de tetriminos lorsque
** la résolution a échoué ou qu'un crash est survenu (probleme de malloc)
**
** Retourne : le statut passé en paramètre (status)
*/

int			clear_tab(char **tetriminos, int i, int status)
{
	while (i >= 0)
	{
		if (tetriminos[i] != NULL)
			ft_strdel(&(tetriminos[i]));
		i--;
	}
	if (tetriminos != NULL)
		ft_strdel(tetriminos);
	tetriminos = NULL;
	return (status);
}

/*
** Fonction en charge d'appeler la fonction d'ajustement des
** tetriminos ( adjust_tetriminos() ) et la fonction de remplissement
** de la map ( fill_map() ).
** 0. On crée un tableau qui va permettre de stocker les nouveaux tetriminos
** 1. On ajuste les tetriminos afin qu'il ai la taille de la map
** 2. Si l'ajustement a réussi, on essaie de remplir la map avec ces nouveaux
**    tetriminos.
** Si l'une des deux étapes a échoué (statut 0), la fonction retourne 0 et sera
** rapellée par la fonction resolve() avec un map_size supérieur.
**
** Retourne : -1 -> crash | 0 -> echec | 1 -> success
*/

static int	can_be_resolved(char **str, char **tab, int map_size)
{
	char	**tetriminos;
	int		ret;

	if ((tetriminos = (char**)malloc(sizeof(char*) *
		ft_array_length((void**)tab) + 1)) == NULL)
		return (-1);
	if ((ret = adjust_tetriminos(tetriminos, tab, map_size)) == -1)
		return (-1);
	if (ret == 0)
		return (0);
	if ((ret = fill_map(str, tetriminos)) == -1)
		return (clear_tab(tetriminos, ft_array_length((void**)tab), -1));
	if (ret == 0)
		return (clear_tab(tetriminos, ft_array_length((void**)tab), 0));
	return (1);
}

/*
** Fonction en charge d'appeler toutes les fonctions nécessaire
** à la résolution du problème d'agencement.
** 1. Définition de la taille de base de la map ( set_map_size() )
** 2. Création de la map ( set_map() ) en fonction de sa taille (point 1)
** 3. Tentative de résolution de l'agencement ( can_be_resolved() )
** 4. Si le point 3 a échoué, création d'une nouvelle map plus grande
**    et on refait le point 3.
**
** Retourne : la map si réussi | NULL si erreur
*/

char		*resolve(char **tab)
{
	char	*str;
	int		map_size;
	int		resolved;
	int		ret;

	map_size = set_map_size(ft_array_length((void**)tab) * 4);
	resolved = 0;
	if ((str = set_map(map_size)) == NULL)
		return (NULL);
	while (resolved == 0)
	{
		resolved = 1;
		if ((ret = can_be_resolved(&str, tab, map_size)) == -1)
			return (NULL);
		if (ret == 0)
		{
			ft_strdel(&str);
			if ((str = set_map(++map_size)) == NULL)
				return (NULL);
			resolved = 0;
		}
	}
	return (str);
}
