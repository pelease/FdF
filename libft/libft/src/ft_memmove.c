/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:23:14 by pelease           #+#    #+#             */
/*   Updated: 2019/09/21 20:23:36 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	d = (char*)dest;
	s = (char*)src;
	if (dest > src)
		while (n >= 1)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	else
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	return (dest);
}
