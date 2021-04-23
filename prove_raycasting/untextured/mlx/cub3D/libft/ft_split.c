/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:52:18 by kpersich          #+#    #+#             */
/*   Updated: 2021/04/08 17:13:47 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strdupe(char const *src, char const *end)
{
	char	*cpy;
	char	*start;

	cpy = (char *)malloc((end - src + 2) * sizeof(char));
	if (!cpy)
		return (0);
	start = cpy;
	while (src != end)
		*(cpy++) = *(src++);
	*cpy = 0;
	return (start);
}

static int	is_sep(char str, char charset)
{
	return (str == charset);
}

static int	final_len(char const *str, char charset,
						char const *begin, char const *end)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
		{
			str++;
			begin = 0;
			end = 0;
		}
		begin = str;
		while (*str && !is_sep(*str, charset))
		{
			end = str;
			str++;
		}
		if (end)
			count++;
	}
	return (count);
}

static char const	*split(char const **str, char c_set,
						char const **begin)
{
	char const	*end;

	end = 0;
	while (**str && is_sep(**str, c_set))
	{
		(*str)++;
		*begin = 0;
		end = 0;
	}
	*begin = *str;
	while (**str && !is_sep(**str, c_set))
	{
		end = *str;
		(*str)++;
	}
	return (end);
}

char	**ft_split(char const *str, char c)
{
	int			set_len;
	int			i;
	char		**strs;
	char const	*begin;
	char const	*end;

	if (!str)
		return (0);
	end = 0;
	begin = 0;
	set_len = final_len(str, c, 0, 0);
	strs = (char **)malloc((set_len + 1) * sizeof(char *));
	if (!strs)
		return (0);
	i = 0;
	while (*str)
	{
		end = split(&str, c, &begin);
		if (end)
			strs[i++] = ft_strdupe(begin, end + 1);
	}
	strs[i] = 0;
	return (strs);
}
