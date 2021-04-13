/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:33:56 by ppunzo            #+#    #+#             */
/*   Updated: 2021/01/13 12:33:57 by ppunzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t src_i;
	size_t dst_i;
	size_t return_v;

	src_i = 0;
	dst_i = ft_strlen(dest);
	return_v = ft_strlen(src) + ft_strlen(dest);
	if (ft_strlen(dest) >= dstsize)
	{
		return (ft_strlen(src) + dstsize);
	}
	if (dstsize > dst_i)
	{
		dstsize = dstsize - ft_strlen(dest) - 1;
		while (src[src_i] && dstsize != 0)
		{
			dest[dst_i] = src[src_i];
			dst_i++;
			src_i++;
			dstsize--;
		}
	}
	dest[dst_i] = '\0';
	return (return_v);
}
