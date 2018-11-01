/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <bjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:50:28 by bjovanov          #+#    #+#             */
/*   Updated: 2018/11/01 17:51:59 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define MAX_TETRIMINOS 26
# define MAX_ROWS 4
# define MAX_COLUMNS 4
# define BUFF_SIZE 21

# include "../libft/libft.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

void	fillit(int argc, char **argv);
int		read_file(int fd, char **str);
char	*resolve(char **tab);
char	*set_map(int map_size);
int		adjust_tetriminos(char **tetriminos, char **tab, int map_size);
int		*set_positions(char **tab);
int		poscmp(char *map, char *tetriminos, int position, char letter);
int		fill_map(char **map, char **tetriminos);
int		set_map_size(int number);
int		clear_tab(char **tetriminos, int i, int status);
#endif
