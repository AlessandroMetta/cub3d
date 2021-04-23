/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:20:00 by kpersich          #+#    #+#             */
/*   Updated: 2021/04/08 17:11:38 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	ptr1 = dst;
	ptr2 = src;
	if (!ptr1 && !ptr2)
		return (0);
	while (n > 0)
	{
		*ptr1 = *ptr2;
		n--;
		ptr1++;
		ptr2++;
	}
	return (dst);
}
