/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:28:00 by ppunzo            #+#    #+#             */
/*   Updated: 2021/04/09 12:58:47 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

static	short	is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' ||
		c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static	short	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}

static	short	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static	int		atoi_e_mammt(const char *str, int lenght, int sign)
{
	long	num;
	int		multi;
	char	c;

	multi = 1;
	num = 0;
	while (lenght >= 0)
	{
		c = str[lenght] - '0';
		num = num + (c * multi);
		multi *= 10;
		lenght--;
	}
	num = num * sign;
	if (num > 2147483647)
		return (0);
	if (num < -2147483648)
		return (-1);
	return (int)num;
}

int				ft_atoi(const char *str)
{
	unsigned int	index;
	int				multiplex;
	int				num_lenght;

	num_lenght = 0;
	index = 0;
	multiplex = 1;
	while (is_space(str[index]))
	{
		index++;
	}
	if (is_sign(str[index]))
	{
		if (str[index] == '-')
			multiplex *= -1;
		index++;
	}
	if (!(is_num(str[index])))
		return (0);
	while (is_num(str[index]))
	{
		index++;
		num_lenght++;
	}
	return (atoi_e_mammt(&str[index - num_lenght], num_lenght - 1, multiplex));
}
