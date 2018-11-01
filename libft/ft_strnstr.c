/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 19:57:11 by bjovanov          #+#    #+#             */
/*   Updated: 2018/10/04 19:57:12 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t needle_length;

	i = 0;
	needle_length = ft_strlen(needle);
	if (haystack[0] == '\0' && *needle == '\0')
		return ((char*)haystack);
	if (haystack[0] == '\0' && *needle != '\0')
		return (NULL);
	while (haystack[i] && i < len)
	{
		if ((i + needle_length) > len)
			break ;
		if (ft_strncmp(&haystack[i], needle, needle_length) == 0)
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
