/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:26:46 by pelease           #+#    #+#             */
/*   Updated: 2019/09/21 20:27:14 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	a = (char*)malloc(sizeof(char) * (i + 1));
	if (a == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (s1[i] != '\0')
		{
			a[i] = s1[i];
			i++;
		}
		a[i] = '\0';
	}
	return (a);
}
