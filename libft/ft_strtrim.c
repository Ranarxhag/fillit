/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:38:00 by bjovanov          #+#    #+#             */
/*   Updated: 2018/10/08 15:34:54 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	size_t			length;

	if (s == NULL)
		return (NULL);
	start = 0;
	while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		&& s[start])
		start++;
	if (start == ft_strlen(s))
		return (ft_strnew(0));
	length = ft_strlen(s);
	while (s[length - 1] == ' ' || s[length - 1] == '\n' ||
	s[length - 1] == '\t')
		length--;
	return (ft_strsub(s, start, length - start));
}
