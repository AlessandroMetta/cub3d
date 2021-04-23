/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:47:33 by kpersich          #+#    #+#             */
/*   Updated: 2021/04/08 17:08:54 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*c_array;

	c_array = (void *)malloc(count * size);
	if (!c_array)
		return (0);
	ft_bzero(c_array, count * size);
	return (c_array);
}
