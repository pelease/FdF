/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:24:12 by pelease           #+#    #+#             */
/*   Updated: 2019/09/21 20:24:19 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*str;

	str = (unsigned char*)s;
	a = c;
	i = 0;
	while (i < n)
	{
		if (str[i] == a)
			return ((void*)(str + i));
		i++;
	}
	return (NULL);
}
