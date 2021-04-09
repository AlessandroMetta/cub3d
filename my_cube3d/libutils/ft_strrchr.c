/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:34:30 by ppunzo            #+#    #+#             */
/*   Updated: 2021/01/13 12:34:31 by ppunzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

static	void	*ft_memchr_rev(const void *s, int c, size_t n)
{
	t_uc		*vect;
	t_uc		stop;

	vect = (t_uc*)s;
	stop = (t_uc)c;
	while (n > 0)
	{
		if (vect[n - 1] == stop)
			return (&vect[n - 1]);
		n--;
	}
	return (NULL);
}

char			*ft_strrchr(const char *s, int c)
{
	return (ft_memchr_rev(s, c, ft_strlen(s) + 1));
}
