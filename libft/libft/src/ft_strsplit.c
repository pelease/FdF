/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:36:25 by pelease           #+#    #+#             */
/*   Updated: 2019/06/24 18:52:26 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		number_of_arr(char const *s, char c)
{
	int i;
	int a;

	a = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			a++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (a);
}

static int		*kolvo_v_every(char const *s, char c, int a)
{
	int *b;
	int i;
	int j;
	int n;

	i = 0;
	n = 0;
	b = (int*)malloc(sizeof(int) * a);
	if (!b)
		return (NULL);
	while (s[i] != '\0' && n < a)
	{
		j = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			j++;
			i++;
		}
		b[n] = j;
		n++;
	}
	return (b);
}

static char		**clean(char **str)
{
	while (str--)
		free(*str);
	free(str);
	return (NULL);
}

static char		**str_razdel(char const *s, char c, int a, int *b)
{
	int		i;
	int		n;
	int		m;
	char	**str;

	n = 0;
	i = 0;
	str = (char**)malloc(sizeof(char*) * (a + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0' && n < a)
	{
		m = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		str[n] = (char*)malloc(sizeof(char) * (b[n] + 1));
		if (!str[n])
			return (clean(str + n));
		while (s[i] != c && s[i] != '\0')
			str[n][m++] = s[i++];
		str[n++][m] = '\0';
	}
	str[a] = NULL;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	int a;
	int *b;

	if (!s)
		return (NULL);
	a = number_of_arr(s, c);
	b = kolvo_v_every(s, c, a);
	return (str_razdel(s, c, a, b));
}
