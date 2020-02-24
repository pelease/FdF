/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:08:17 by pelease           #+#    #+#             */
/*   Updated: 2019/09/21 21:08:21 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s)
	{
		str = (char*)malloc(sizeof(char) * (len + 1));
		if (str)
		{
			while (s[start] && i < len)
			{
				str[i] = s[start];
				i++;
				start++;
			}
			str[i] = '\0';
			return (str);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
