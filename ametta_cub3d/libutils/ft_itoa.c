/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 09:56:50 by ppunzo            #+#    #+#             */
/*   Updated: 2021/01/16 09:56:51 by ppunzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

static size_t	ft_num_size(long int num)
{
	long int	divider;
	size_t		len;

	len = 0;
	divider = 1;
	if (num == 0)
		return (1);
	if (num < 0)
		num *= -1;
	while (num / divider != 0)
	{
		divider *= 10;
		len++;
		if (num / divider == 0)
			return (len);
	}
	return (1);
}

static void		ft_write_num(char *string, long num, size_t len)
{
	int multi;

	multi = 10;
	if (num < 0)
		num *= -1;
	while (len > 0)
	{
		string[len - 1] = ((num % multi) + 48);
		num = num / 10;
		len--;
	}
}

char			*ft_itoa(int n)
{
	char	*num_s;
	int		sign;
	int		num_len;

	sign = 0;
	num_len = ft_num_size(n);
	if (n < 0)
		sign = 1;
	num_s = ft_calloc(num_len + sign + 1, sizeof(char));
	if (!num_s)
		return (0);
	if (sign == 1)
		num_s[0] = '-';
	ft_write_num(&num_s[sign], (long)n, num_len);
	return (num_s);
}

char			*ft_uitoa(unsigned int n)
{
	char	*num_s;
	int		sign;
	int		num_len;

	sign = 0;
	num_len = ft_num_size(n);
	if (n < 0)
		sign = 1;
	num_s = ft_calloc(num_len + sign + 1, sizeof(char));
	if (!num_s)
		return (0);
	if (sign == 1)
		num_s[0] = '-';
	ft_write_num(&num_s[sign], (long)n, num_len);
	return (num_s);
}
