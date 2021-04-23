/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:30:59 by kpersich          #+#    #+#             */
/*   Updated: 2021/04/08 17:19:53 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		return (NULL);
	ft_memmove(ret, ptr, ft_strlen((char *)ptr));
	((char *)ret)[ft_strlen((char *)ptr)] = 0;
	ft_bzero(ptr, ft_strlen((const char *)ptr));
	free(ptr);
	ptr = NULL;
	return (ret);
}
