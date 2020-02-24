/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 14:34:06 by pelease           #+#    #+#             */
/*   Updated: 2019/09/21 20:30:33 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	a;
	char	*s1;

	i = 0;
	a = c;
	s1 = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == a)
			s1 = (char*)(s + i);
		i++;
	}
	if (s[i] == a)
		s1 = (char*)(s + i);
	if (s1 != NULL)
		return (s1);
	return (NULL);
}
