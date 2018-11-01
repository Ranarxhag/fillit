/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <bjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:37:22 by bjovanov          #+#    #+#             */
/*   Updated: 2018/10/10 21:55:09 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	new = NULL;
	if (f == NULL)
		return (NULL);
	if (lst)
	{
		new = ft_lstnew(lst->content, lst->content_size);
		if (new == NULL)
			return (NULL);
		new = f(new);
		if (new == NULL)
			return (NULL);
		if (lst->next)
			new->next = ft_lstmap(lst->next, f);
	}
	return (new);
}
