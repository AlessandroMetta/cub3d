/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 09:13:30 by ppunzo            #+#    #+#             */
/*   Updated: 2021/01/13 09:13:35 by ppunzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	t_uc	*from;
	t_uc	*to;
	t_uc	stop;
	size_t	index;

	index = 0;
	from = (t_uc*)src;
	to = (t_uc*)dst;
	stop = (t_uc)c;
	while (index < n)
	{
		to[index] = from[index];
		if (to[index] == stop)
			return (&to[index += 1]);
		index++;
	}
	return (NULL);
}
