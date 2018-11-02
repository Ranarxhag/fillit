/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <bjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 22:51:24 by bjovanov          #+#    #+#             */
/*   Updated: 2018/11/01 17:50:07 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Fonction en charge de supprimer l'overflow d'un nouveau tetriminos
** Exemple :
** (actuel)  "....\n..##\n...#\n...#\n"
** (nouveau) "##\n...#\n...#"
**
** Retourne : tetriminos "découpé" si reussi | NULL -> crash
*/

static char	*remove_overflow(char *tetriminos, char letter)
{
	size_t	start;
	size_t	len;

	start = 0;
	len = ft_strlen(tetriminos);
	while (tetriminos[start] && tetriminos[start] != letter)
		start++;
	while (len > 0 && tetriminos[len - 1] != letter)
		len--;
	return (ft_strsub(tetriminos, start, len - start));
}

/*
** Fonction appelée par adjust_tetriminos() en charger de placer le
** tetriminos en cours dans une grille inférieure à 4
** On supprime d'abord l'overflow via remove_overflow(), c'est-à-dire
** que l'on va retirer les caractères avant le premier '#' et après
** le dernier '#'
** Exemple avec un map_size à 3 :
** (actuel)  "....\n..##\n...#\n...#\n"
** (actuel)  "##\n...#\n...#" <-- on supprime l'overflow
** (nouveau) "##.\n.#.\n.#.\n"
** (nouveau) "##.\n.#.\n.#" <-- on supprime l'overflow
**
** Retourne : -1 -> crash | 0 -> impossible | 1 -> success
*/

static int	crop(char **tetriminos, char *tab, int map_size, char letter)
{
	char	*temp;
	int		line;
	int		i;

	if ((temp = remove_overflow(tab, letter)) == NULL)
		return (-1);
	i = 0;
	line = 0;
	while (temp[i])
	{
		if (temp[i] == letter && (i + line > (int)ft_strlen(tetriminos[0])
			|| tetriminos[0][i + line] == '\n'))
			return (0);
		if (temp[i] == letter)
			tetriminos[0][i + line] = temp[i];
		if (temp[i] == '\n')
			line += ((4 - map_size) * -1);
		i++;
	}
	ft_strdel(&temp);
	temp = tetriminos[0];
	if ((tetriminos[0] = remove_overflow(temp, letter)) == NULL)
		return (clear_tab(&temp, 0, -1));
	ft_strdel(&temp);
	return (1);
}

/*
** Fonction appelée par adjust_tetriminos() en charger de placer le
** tetriminos en cours dans une grille supérieure à 4.
** Exemple avec un map_size à 5 :
** (actuel)  "....\n..##\n...#\n...#\n"
** (nouveau) ".....\n...##\n....#\n....#\n"
** Enfin, on va supprimer l'overflow via remove_overflow(), c'est-à-dire
** que l'on va retirer les caractères avant le premier '#' et après
** le dernier '#'.
** (final)   "##\n....#\n....#"
**
** Retourne : -1 -> crash | 1 -> success
*/

static int	adjust(char **tetriminos, char *tab, int map_size, char letter)
{
	int		i;
	int		line;
	char	*temp;

	i = 0;
	line = 0;
	temp = NULL;
	while (tab[i])
	{
		if (tab[i] == letter)
			tetriminos[0][i + (map_size - 4) + line] = tab[i];
		if (tab[i] == '\n')
			line += (map_size - 4);
		i++;
	}
	temp = tetriminos[0];
	if ((tetriminos[0] = remove_overflow(temp, letter)) == NULL)
		return (clear_tab(&temp, 0, -1));
	ft_strdel(&temp);
	return (1);
}

/*
** Fonction appelée par can_be_resolved() en charge d'ajuster les tetriminos
** en fonction de la taille de la map.
** On boucle sur chaque tetriminos contenu dans **tab
** 1. On crée un nouveau tetriminos vide via set_map() en fonction de la
**    taille de map_size
** 2. Si la taille de la map est inférieure à 4, on appelle crop() qui
**    va se charger de "découper" dans les tetriminos pour les ajuster
**    Si la taille de la map est supérieure à 4, on appelle adjust() qui
**    va se charger de placer le tetriminos actuel dans une grille de la
**    taille de map_size
**
** Retourne : -1 -> crash | 0 si impossible d'ajuster | 1 -> success
*/

int			adjust_tetriminos(char **tetriminos, char **tab, int map_size)
{
	int		i;
	char	letter;
	int		ret;
	int		count;

	count = ft_array_length((void**)tab);
	i = 0;
	letter = 'A';
	while (i < count)
	{
		if ((tetriminos[i] = set_map(map_size)) == NULL)
			return (-1);
		if (map_size < 4
			&& (ret = crop(&(tetriminos[i]), tab[i], map_size, letter)) == -1)
			return (clear_tab(tetriminos, i, -1));
		if (map_size >= 4
			&& (ret = adjust(&(tetriminos[i]), tab[i], map_size, letter)) == -1)
			return (clear_tab(tetriminos, i, -1));
		if (ret == 0)
			return (clear_tab(tetriminos, i, 0));
		i++;
		letter++;
	}
	tetriminos[i] = 0;
	return (1);
}
