/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:28:39 by ametta            #+#    #+#             */
/*   Updated: 2021/04/26 14:28:43 by ametta           ###   ########.fr       */
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
