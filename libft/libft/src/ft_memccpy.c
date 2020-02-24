/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:19:04 by pelease           #+#    #+#             */
/*   Updated: 2019/09/21 20:21:26 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	a;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	i = 0;
	a = (unsigned char)c;
	while (i < n)
	{
		*(d + i) = *(s + i);
		if (s[i] == a)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
