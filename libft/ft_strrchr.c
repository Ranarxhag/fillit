/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:53:18 by bjovanov          #+#    #+#             */
/*   Updated: 2018/10/04 17:53:19 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t			i;
	char			*occ;

	i = 0;
	occ = NULL;
	if (*str == '\0' && c == '\0')
		return ((char*)str);
	while (str[i])
	{
		if (str[i] == c)
			occ = (char*)&str[i];
		else if (str[i + 1] == c)
			occ = (char*)&str[i + 1];
		i++;
	}
	return (occ);
}
