/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <bjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:48:14 by bjovanov          #+#    #+#             */
/*   Updated: 2018/11/08 13:20:42 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("usage: fillit <filename>", 2);
		exit(EXIT_FAILURE);
	}
	fillit(argv);
	return (0);
}
