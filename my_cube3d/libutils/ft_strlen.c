/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:33:17 by ppunzo            #+#    #+#             */
/*   Updated: 2021/01/13 12:33:20 by ppunzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

size_t	ft_strlen(const char *str)
{
	size_t		index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
		index++;
	return (index);
}
