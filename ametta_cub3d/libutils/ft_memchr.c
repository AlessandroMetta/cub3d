/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:42:51 by ppunzo            #+#    #+#             */
/*   Updated: 2021/01/13 11:42:53 by ppunzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;
	t_uc	*vect;
	t_uc	stop;

	vect = (t_uc*)s;
	index = 0;
	stop = (t_uc)c;
	while (index < n)
	{
		if (vect[index] == stop)
			return (&vect[index]);
		index++;
	}
	return (NULL);
}
