/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <bjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 21:43:48 by bjovanov          #+#    #+#             */
/*   Updated: 2018/10/31 15:39:27 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strreplace(char *str, int search, int replace)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == search)
			str[i] = replace;
		i++;
	}
}
