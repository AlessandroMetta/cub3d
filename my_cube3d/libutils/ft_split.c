/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:33:33 by ppunzo            #+#    #+#             */
/*   Updated: 2021/01/15 16:33:35 by ppunzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

static	int		ft_count_word(const char *s, char c)
{
	int index;
	int count;

	count = 0;
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c)
			index++;
		else
		{
			count++;
			while (s[index] != '\0' && s[index] != c)
				index++;
		}
	}
	return (count);
}

static	char	**ft_mat(const char *s, char c, char **matrix, size_t word_c)
{
	size_t index;
	size_t index_2;
	size_t len;

	index = 0;
	index_2 = 0;
	while (index < word_c)
	{
		if (s[index_2] != c)
		{
			len = index_2;
			while (s[len] && s[len] != c)
				len++;
			matrix[index] = (char *)malloc(sizeof(char) * (len - index_2 + 1));
			if (matrix[index] == NULL)
				return (NULL);
			ft_strlcpy(matrix[index], &s[index_2], (len - index_2 + 1));
			index++;
			index_2 = len;
		}
		else
			index_2++;
	}
	return (matrix);
}

char			**ft_split(const char *s, char c)
{
	char	**matrix;
	size_t	word_c;

	if (!s)
		return (NULL);
	word_c = ft_count_word(s, c);
	if (!(matrix = (char **)malloc(sizeof(char *) * (word_c + 1))))
		return (NULL);
	matrix[word_c] = NULL;
	return (ft_mat(s, c, matrix, word_c));
}
