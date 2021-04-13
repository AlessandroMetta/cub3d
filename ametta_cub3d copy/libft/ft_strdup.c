/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:08:01 by ametta            #+#    #+#             */
/*   Updated: 2021/04/13 11:57:21 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	cpy_len;

	cpy_len = ft_strlen(s1);
	cpy = (char *)ft_calloc(cpy_len + 1, sizeof(char));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s1, cpy_len);
	return (cpy);
}
