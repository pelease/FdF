/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:10:53 by pelease           #+#    #+#             */
/*   Updated: 2019/09/19 19:11:20 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		number(int n)
{
	int i;

	i = 1;
	while (n <= -10 || n >= 10)
	{
		n = n / 10;
		i = i * 10;
	}
	return (i);
}

static int		max_n(int n)
{
	int i;
	int x;

	i = 0;
	x = 0;
	if (n < 0)
		x = 1;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (x + i);
}

static int		solving(char *str, int b, int i, int n)
{
	if (n < 0)
	{
		str[i++] = '-';
		n = n * (-1);
	}
	while (b > 0)
	{
		str[i] = (n / b) % 10 + '0';
		i++;
		b /= 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		a;
	int		i;
	int		b;
	char	*str;

	b = number(n);
	a = 0;
	i = 0;
	str = (char*)malloc(sizeof(char) * (max_n(n) + 1));
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{
		n = -2147483647;
		a = 1;
	}
	i = solving(str, b, i, n);
	if (a == 1)
		str[i - 1] = '8';
	str[i] = '\0';
	return (str);
}
