/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <bjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:19:21 by bjovanov          #+#    #+#             */
/*   Updated: 2018/11/08 13:06:17 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** BASE DU PROJET
** Appelle consécutivement les fonctions de vérification
** du fichier de description ( read_file() ), de transformation
** de ce dernier en tableau de tetriminos ( ft_strstrsplit() ),
** de résolution et de backtracking ( resolve() ) et finalement,
** affiche le résultat
*/

void	fillit(char **argv)
{
	int		fd;
	char	*str;
	char	**tab;

	fd = open(argv[1], O_RDONLY);
	if (read_file(fd, &str) == 0)
	{
		ft_putendl_fd("error", 1);
		exit(EXIT_FAILURE);
	}
	if ((tab = ft_strstrsplit(str, "\n\n")) == NULL)
		exit(EXIT_FAILURE);
	ft_strdel(&str);
	if (ft_array_length((void**)tab) > 26)
	{
		clear_tab(tab, ft_array_length((void**)tab) - 1, 1);
		ft_putendl_fd("error", 1);
		exit(EXIT_FAILURE);
	}
	if ((str = resolve(tab)) == NULL)
		exit(EXIT_FAILURE);
	ft_putstr(str);
	ft_strdel(&str);
}
