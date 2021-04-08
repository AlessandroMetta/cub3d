/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:15:50 by ametta            #+#    #+#             */
/*   Updated: 2021/01/26 16:31:29 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *todel;

	while (*lst)
	{
		todel = *lst;
		*lst = todel->next;
		(*del)(todel->content);
		free(todel);
	}
	*lst = NULL;
}
