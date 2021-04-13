/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:52:58 by ppunzo            #+#    #+#             */
/*   Updated: 2021/01/15 11:52:59 by ppunzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

char	*ft_strdup(const char *s1)
{
	char	*duplicated;
	size_t	lenght;

	lenght = ft_strlen(s1) + 1;
	duplicated = (char *)ft_calloc(lenght, sizeof(char));
	ft_strlcpy(duplicated, s1, lenght);
	return (duplicated);
}
