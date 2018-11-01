/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <bjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 22:59:07 by bjovanov          #+#    #+#             */
/*   Updated: 2018/10/03 23:28:06 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;
	unsigned char			ch;
	size_t					i;

	d = (unsigned char*)dest;
	s = (const unsigned char*)src;
	i = 0;
	ch = (unsigned char)c;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == ch)
			return (&d[i + 1]);
		i++;
	}
	return (NULL);
}
