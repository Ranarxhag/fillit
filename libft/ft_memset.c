/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <bjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 18:53:05 by bjovanov          #+#    #+#             */
/*   Updated: 2018/10/03 23:01:03 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	char			*str;
	unsigned char	d;

	d = (unsigned char)c;
	str = (char*)s;
	i = 0;
	while (i < n)
	{
		str[i] = d;
		i++;
	}
	return (str);
}
