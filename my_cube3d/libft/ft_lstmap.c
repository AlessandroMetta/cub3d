/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:16:28 by ametta            #+#    #+#             */
/*   Updated: 2021/01/26 16:35:48 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *map;

	if (!lst || !f)
		return (NULL);
	if (!(map = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&map, del);
		return (NULL);
	}
	map->next = ft_lstmap(lst->next, f, del);
	return (map);
}
