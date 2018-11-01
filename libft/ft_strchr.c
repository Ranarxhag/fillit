/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:27:28 by bjovanov          #+#    #+#             */
/*   Updated: 2018/10/04 17:27:29 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t			i;

	i = 0;
	if (str[0] == '\0' && c == '\0')
		return ((char*)str);
	while (str[i])
	{
		if (str[i] == c)
			return ((char*)&str[i]);
		else if (str[i + 1] == c)
			return ((char*)&str[i + 1]);
		i++;
	}
	return (NULL);
}
