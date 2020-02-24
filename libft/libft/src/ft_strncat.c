/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:29:12 by pelease           #+#    #+#             */
/*   Updated: 2019/09/21 20:29:14 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t max_s1;
	size_t i;

	i = 0;
	max_s1 = 0;
	while (s1[max_s1] != '\0')
		max_s1++;
	while (i < n && s2[i] != '\0')
	{
		s1[max_s1] = s2[i];
		i++;
		max_s1++;
	}
	s1[max_s1] = '\0';
	return (s1);
}
