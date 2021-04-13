/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:33:41 by ppunzo            #+#    #+#             */
/*   Updated: 2021/01/13 12:33:42 by ppunzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	if (!dst)
		return (0);
	ft_memccpy(dst, src, '\0', dstsize);
	if (dstsize > 0)
		dst[dstsize - 1] = '\0';
	return (ft_strlen(src));
}
