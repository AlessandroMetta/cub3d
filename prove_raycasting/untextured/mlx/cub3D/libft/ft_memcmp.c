/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:45:40 by kpersich          #+#    #+#             */
/*   Updated: 2021/04/08 17:11:26 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = s1;
	ptr2 = s2;
	while (n > 0 && (ptr1 || ptr2))
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		n--;
		ptr1++;
		ptr2++;
	}
	return (0);
}
