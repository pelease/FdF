/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:29:41 by pelease           #+#    #+#             */
/*   Updated: 2019/09/21 20:30:03 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	a;

	i = 0;
	a = c;
	while (s[i] != '\0')
	{
		if (s[i] == a)
			return ((char*)(s + i));
		i++;
	}
	if (s[i] == a)
		return ((char*)(s + i));
	return (NULL);
}
