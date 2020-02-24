/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 16:41:17 by pelease           #+#    #+#             */
/*   Updated: 2019/09/21 20:50:51 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*x1;
	unsigned char	*x2;

	i = 0;
	x1 = (unsigned char*)s1;
	x2 = (unsigned char*)s2;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (x1[i] == x2[i])
			i++;
		else
			return (x1[i] - x2[i]);
	}
	return (x1[i] - x2[i]);
}
