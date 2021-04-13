/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:04:45 by ppunzo            #+#    #+#             */
/*   Updated: 2021/01/16 14:04:47 by ppunzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	s_i;

	s_i = 0;
	if (!s)
		return (0);
	res = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!res)
		return (0);
	while (s[s_i])
	{
		res[s_i] = f(s_i, s[s_i]);
		s_i++;
	}
	return (res);
}
