/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:02:51 by pelease           #+#    #+#             */
/*   Updated: 2019/09/21 20:52:04 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*x1;
	unsigned char	*x2;

	i = 0;
	x1 = (unsigned char*)s1;
	x2 = (unsigned char*)s2;
	while (x1[i] != '\0' && x2[i] != '\0' && i < n)
	{
		if (x1[i] == x2[i])
			i++;
		else
			return (x1[i] - x2[i]);
	}
	if (i == n)
		return (0);
	return (x1[i] - x2[i]);
}
