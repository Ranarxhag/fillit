/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 19:13:02 by bjovanov          #+#    #+#             */
/*   Updated: 2018/10/04 19:13:03 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[i])
	{
		if (ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0)
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
