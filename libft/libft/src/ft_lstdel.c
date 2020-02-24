/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 18:31:12 by pelease           #+#    #+#             */
/*   Updated: 2019/09/29 18:34:45 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *list;
	t_list *list2;

	if (alst && *alst)
	{
		list2 = *alst;
		while (list2)
		{
			list = list2;
			list2 = list->next;
			del(list->content, list->content_size);
			free(list);
			list = NULL;
		}
		*alst = NULL;
	}
}
