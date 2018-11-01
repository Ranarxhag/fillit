/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:12:42 by bjovanov          #+#    #+#             */
/*   Updated: 2018/10/08 15:20:50 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert_to_int(const char *str, int sign)
{
	int		i;
	long	number;
	long	overflow;

	i = 0;
	number = 0;
	while (ft_isdigit(str[i]))
	{
		overflow = number;
		number = (number * 10) + (str[i] - 48);
		if (overflow && (number ^ overflow) < 0)
			return ((sign == 1) ? -1 : 0);
		i++;
	}
	return ((int)number * sign);
}

int			ft_atoi(const char *str)
{
	int i;
	int sign;

	i = 0;
	sign = 1;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		else if (str[i] == '-' || str[i] == '+')
		{
			if (!ft_isdigit(str[i + 1]))
				return (0);
			sign = (str[i] == '-' ? -sign : sign);
			i++;
		}
		else
			break ;
	}
	return (convert_to_int(&str[i], sign));
}
