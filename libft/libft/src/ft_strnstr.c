/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 15:33:49 by pelease           #+#    #+#             */
/*   Updated: 2019/09/14 18:44:06 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*checker(const char *s1, const char *s2, size_t len, size_t n)
{
	size_t i;
	size_t j;
	size_t check;

	i = 0;
	j = 0;
	check = i;
	while (s1[i] != '\0' && s2[j] != '\0' && check < len)
	{
		if (s1[i] == s2[j])
		{
			i++;
			j++;
			if ((j == n || i == len) && s2[j] == '\0')
				return ((char*)(s1 + i - j));
			check++;
		}
		else
		{
			i = i - j + 1;
			check = i;
			j = 0;
		}
	}
	return (NULL);
}

char			*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t n;

	n = ft_strlen(s2);
	if (ft_strlen(s1) == 0)
		return (NULL);
	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	return (checker(s1, s2, len, n));
}
