/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 11:16:17 by bjovanov          #+#    #+#             */
/*   Updated: 2018/10/04 11:16:18 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	unsigned char		occ;
	const unsigned char	*s;

	i = 0;
	occ = (unsigned char)c;
	s = (const unsigned char*)str;
	while (i < n)
	{
		if (s[i] == occ)
			return ((unsigned char*)&s[i]);
		i++;
	}
	return (NULL);
}
