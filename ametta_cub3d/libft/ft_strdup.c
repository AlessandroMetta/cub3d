/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:08:01 by ametta            #+#    #+#             */
/*   Updated: 2021/04/14 12:54:55 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*duplicated;
	size_t	lenght;

	lenght = ft_strlen(s1) + 1;
	duplicated = (char *)ft_calloc(lenght, sizeof(char));
	ft_strlcpy(duplicated, s1, lenght);
	return (duplicated);
}
