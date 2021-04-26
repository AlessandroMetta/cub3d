/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:21:48 by ametta            #+#    #+#             */
/*   Updated: 2021/04/26 14:47:00 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*output;

	i = 0;
	while (s[i] != 0)
		i++;
	output = malloc(sizeof(char) * (i + 1));
	if (!output)
		return (NULL);
	output[i] = '\0';
	i = 0;
	while (s[i] != 0)
	{
		output[i] = (*f)(i, s[i]);
		i++;
	}
	if (output == NULL)
		return (NULL);
	return (output);
}
