/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:09:25 by ppunzo            #+#    #+#             */
/*   Updated: 2021/01/15 15:09:26 by ppunzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left_i;
	size_t	right_trim;
	size_t	right_i;
	char	*sub;

	right_trim = 0;
	left_i = 0;
	if (!s1)
		return (NULL);
	right_i = ft_strlen(s1);
	while (ft_strchr(set, s1[left_i]))
		left_i++;
	while (ft_strchr(set, s1[right_i]))
	{
		right_i--;
		right_trim++;
	}
	if (!s1[left_i])
		return (0);
	sub = ft_substr(s1, left_i, ft_strlen(&s1[left_i]) - right_trim + 1);
	return (sub);
}
