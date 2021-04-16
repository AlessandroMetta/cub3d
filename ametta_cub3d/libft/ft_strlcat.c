/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:19:46 by ametta            #+#    #+#             */
/*   Updated: 2021/04/13 11:45:31 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c1;
	size_t	c2;

	c1 = ft_strlen(dst);
	c2 = 0;
	if (dstsize <= c1)
		return (dstsize + ft_strlen(src));
	while (c1 < dstsize - 1 && src[c2] != '\0')
		dst[c1++] = src[c2++];
	dst[c1] = 0;
	while (src[c2++] != '\0')
		c1++;
	return (c1);
}
