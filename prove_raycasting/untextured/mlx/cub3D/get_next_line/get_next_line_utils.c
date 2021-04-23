/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:54:11 by kpersich          #+#    #+#             */
/*   Updated: 2021/04/08 17:00:44 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_realloc_gnl(void *ptr, ssize_t more_size)
{
	void	*ret;

	ret = malloc((ft_strlen(ptr) + more_size) * sizeof(char));
	if (!(ret))
		return (0);
	ret = ft_strcpy(ret, ptr);
	free(ptr);
	ptr = NULL;
	return (ret);
}
