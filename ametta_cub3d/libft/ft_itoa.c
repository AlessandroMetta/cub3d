/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:06:17 by ametta            #+#    #+#             */
/*   Updated: 2021/04/26 14:47:46 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit(int n)
{
	int	digit;

	digit = 0;
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit + 1);
}

static char	*ft_isneg(int n)
{
	char	*str;
	int		i;

	n *= -1;
	i = ft_digit(n) + 1;
	str = (char *)malloc(i * sizeof(char));
	if (!str)
		return (NULL);
	str[--i] = 0;
	while (--i > 0)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
	}
	str[i] = '-';
	if (str == 0)
		return (NULL);
	return (str);
}

static char	*ft_ispos(int n)
{
	char	*str;
	int		i;

	i = ft_digit(n);
	str = (char *)malloc(i * sizeof(char));
	if (!str)
		return (NULL);
	str[--i] = 0;
	while (--i >= 0)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
	}
	if (str == 0)
		return (NULL);
	return (str);
}

static char	*ft_minint(int n)
{
	char	*str;
	int		i;

	n /= -10;
	i = ft_digit(n) + 2;
	str = (char *)malloc(i * sizeof(char));
	if (!str)
		return (NULL);
	str[--i] = 0;
	str[--i] = 8 + 48;
	while (--i > 0)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
	}
	str[i] = '-';
	if (str == 0)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == -0 || n == +0)
	{
		str = malloc(2 * sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = 0;
		return (str);
	}
	else if (n == -2147483648)
		return (ft_minint(n));
	else if (n < 0)
		return (ft_isneg(n));
	else if (n > 0)
		return (ft_ispos(n));
	else
		return (NULL);
}
