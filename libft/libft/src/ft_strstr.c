/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 15:00:00 by pelease           #+#    #+#             */
/*   Updated: 2019/05/05 15:00:34 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;
	size_t check;

	j = 0;
	i = 0;
	check = i;
	while (haystack[i] != '\0' && ft_strlen(haystack) >= ft_strlen(needle))
	{
		if (haystack[i] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char*)(haystack + i - j));
			i++;
			j++;
		}
		else
		{
			j = 0;
			i = ++check;
		}
	}
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	return (NULL);
}
