/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:29:08 by ametta            #+#    #+#             */
/*   Updated: 2021/01/14 16:35:59 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	ptr = (void*)malloc(nitems * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nitems * size);
	return (ptr);
}
