/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:15:10 by pelease           #+#    #+#             */
/*   Updated: 2019/09/21 20:17:09 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	a;
	size_t			i;
	char			*s1;

	s1 = (char*)s;
	i = 0;
	a = (unsigned char)c;
	while (i < n)
	{
		*(s1 + i) = a;
		i++;
	}
	return ((void*)s);
}
