/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:24:31 by pelease           #+#    #+#             */
/*   Updated: 2019/09/21 20:26:15 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*x;
	const unsigned char	*y;
	size_t				i;
	int					a;

	if (n == 0)
		return (0);
	i = 0;
	a = 0;
	x = (unsigned char*)s1;
	y = (unsigned char*)s2;
	while (i < n)
	{
		if (x[i] == y[i])
			i++;
		else
		{
			a = x[i] - y[i];
			return (a);
		}
	}
	return (a);
}
