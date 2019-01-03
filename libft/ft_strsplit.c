/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <bjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 14:52:11 by bjovanov          #+#    #+#             */
/*   Updated: 2018/10/12 22:17:16 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*remove_tab(char **tab, int index)
{
	while (index >= 0)
	{
		free(tab[index]);
		index--;
	}
	free(tab);
	return (NULL);
}

static int		count_words(char const *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i + 1] == '\0')
		{
			if (s[i] != c)
				words++;
		}
		else
		{
			if (s[i] != c && s[i + 1] == c)
				words++;
		}
		i++;
	}
	return (words);
}

static char		*create_word(char const *s, char c)
{
	char	*str;
	int		length;

	length = 0;
	while (s[length] != c && s[length] != '\0')
		length++;
	str = ft_strndup(s, length);
	if (str == NULL)
		return (NULL);
	return (str);
}

static char		**create_tab(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	str = (char**)malloc(sizeof(char*) * (count_words(s, c) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0') ||
			(i == 0 && s[i] != c))
		{
			str[j] = create_word((i == 0 && s[i] != c) ? &s[i] : &s[i + 1], c);
			if (str[j] == NULL)
				return (remove_tab(str, j));
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	if (s == NULL)
		return (NULL);
	return (create_tab(s, c));
}
