/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 08:18:17 by ppunzo            #+#    #+#             */
/*   Updated: 2021/01/13 08:18:23 by ppunzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	t_uc *from;
	t_uc *to;

	from = (t_uc*)src;
	to = (t_uc*)dst;
	if (from == NULL && to == NULL)
		return (NULL);
	while (n-- > 0)
		*to++ = *from++;
	return (dst);
}
