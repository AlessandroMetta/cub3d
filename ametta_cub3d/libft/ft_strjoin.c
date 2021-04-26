/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:52:08 by ametta            #+#    #+#             */
/*   Updated: 2021/04/26 14:46:53 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (!s1 || !s2)
		return (0);
	res = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!res)
		return (0);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	ft_strlcpy(&res[ft_strlen(res)], s2, ft_strlen(s2) + 1);
	return (res);
}
