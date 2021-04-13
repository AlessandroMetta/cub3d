/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:38:29 by ppunzo            #+#    #+#             */
/*   Updated: 2021/01/15 14:38:31 by ppunzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *res;

	if (!s1 || !s2)
		return (0);
	res = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!res)
		return (0);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	ft_strlcpy(&res[ft_strlen(res)], s2, ft_strlen(s2) + 1);
	return (res);
}
