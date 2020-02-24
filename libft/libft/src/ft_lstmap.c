/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 21:32:15 by pelease           #+#    #+#             */
/*   Updated: 2019/09/29 21:43:51 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *exmp;
	t_list *made;

	if (!lst)
		return (NULL);
	if (!(exmp = f(lst)))
	{
		free(exmp);
		return (NULL);
	}
	made = exmp;
	lst = lst->next;
	while (lst)
	{
		if (!(exmp->next = f(lst)))
		{
			free(exmp->next);
			return (NULL);
		}
		exmp = exmp->next;
		lst = lst->next;
	}
	return (made);
}
