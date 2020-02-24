/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 14:49:27 by pelease           #+#    #+#             */
/*   Updated: 2019/09/21 21:12:53 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		start(char const *s)
{
	int i;
	int max;

	max = ft_strlen(s);
	i = 0;
	if (s)
	{
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
			i++;
		if (i == max)
			i = -10;
		return (i);
	}
	return (-1);
}

static int		end(char const *s)
{
	int max;

	if (s)
	{
		max = ft_strlen(s);
		while (s[max - 1] == ' ' || s[max - 1] == '\n' || s[max - 1] == '\t')
			max--;
		return (max);
	}
	return (0);
}

static char		*triming(int i, int max, char *str, const char *s)
{
	if (str)
	{
		str[max - i] = '\0';
		while (i < max)
		{
			str[max - i - 1] = s[max - 1];
			max--;
		}
		return (str);
	}
	return (NULL);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		max;
	char	*str;

	if (s)
	{
		i = start(s);
		if (i == -10)
		{
			str = (char*)malloc(sizeof(char) * 1);
			str[0] = '\0';
			return (str);
		}
		max = end(s);
		str = (char*)malloc(sizeof(char) * (max - i + 1));
		return (triming(i, max, str, s));
	}
	return (NULL);
}
