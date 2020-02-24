/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:13:45 by pelease           #+#    #+#             */
/*   Updated: 2019/05/05 18:14:14 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check(const char *str, int *a)
{
	size_t i;

	i = 0;
	while (!(((str[i] >= '0') && (str[i] <= '9')) || (*a == -1) || (*a == 2)))
	{
		if (str[i] == '-')
			*a = -1;
		if (str[i] == '+')
			*a = 2;
		if (str[i] == ' ' || str[i] == '	' || str[i] == '+' || str[i] == '-')
			i++;
		else if (str[i] == '\n' || str[i] == '\t' || str[i] == '\f'
				|| str[i] == '\v' || str[i] == '\r')
			i++;
		else
			return (0);
	}
	return (i);
}

int				ft_atoi(const char *str)
{
	size_t					i;
	int						a;
	unsigned long long int	res;

	res = 0;
	a = 0;
	i = check(str, &a);
	while (str[i] != '\0' && ((str[i] >= '0') && (str[i] <= '9')))
		res = 10 * res + (str[i++] - '0');
	if (res > 9223372036854775807 && a == -1)
		return (0);
	if (res >= 9223372036854775807 && (a == 0 || a == 2))
		return (-1);
	if (a == -1)
		res = -res;
	return (res);
}
