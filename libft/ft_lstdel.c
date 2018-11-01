/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <bjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:21:03 by bjovanov          #+#    #+#             */
/*   Updated: 2018/10/10 17:36:10 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	ft_lstdel((&(*alst)->next), del);
	ft_lstdelone(alst, del);
}
