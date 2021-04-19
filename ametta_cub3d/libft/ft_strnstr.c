/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:12:32 by ametta            #+#    #+#             */
/*   Updated: 2021/04/19 12:20:24 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (haystack[i] && needle[j] && len > 0)
	{
		j = 0;
		if (needle[j] != haystack[i])
		{
			i++;
			len--;
		}
		while (needle[j] == haystack[i] && len > 0 && haystack[i])
		{
			j++;
			i++;
			len--;
		}
	}
	if (needle[j] == '\0')
		return ((char *)haystack + (i - j));
	return (NULL);
}
