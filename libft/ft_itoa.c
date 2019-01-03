/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:52:39 by bjovanov          #+#    #+#             */
/*   Updated: 2018/10/08 15:43:50 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits_number(int n)
{
	int result;

	result = (n < 0 ? 1 : 0);
	if (n < 0)
	{
		while (n < 0)
		{
			result++;
			n /= 10;
		}
	}
	else
	{
		while (n > 0)
		{
			result++;
			n /= 10;
		}
	}
	return (result);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		n_digits;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	n_digits = digits_number(n);
	str = ft_strnew(n_digits);
	if (str == NULL)
		return (NULL);
	i = n_digits - 1;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	return (str);
}
