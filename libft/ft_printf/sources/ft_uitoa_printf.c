/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 22:50:01 by pelease           #+#    #+#             */
/*   Updated: 2020/02/05 22:50:02 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int			str_size(t_fpf *ft_pf, t_arg arg)
{
	int				i;

	i = 0;
	if (arg.num_u == 0 && ft_pf->pr_sign == 'Y' && ft_pf->precision == 0)
		return (0);
	if (arg.num_u == 0)
		i++;
	while (arg.num_u != 0)
	{
		if (ft_pf->type == 'u')
			arg.num_u /= 10;
		else if (ft_pf->type == 'o')
			arg.num_u /= 8;
		else
			arg.num_u /= 16;
		i++;
	}
	return (i);
}

void				ft_uitoa_printf(t_fpf *ft_pf, t_arg *arg)
{
	arg->strlen = str_size(ft_pf, *arg);
	all_conversion(arg, ft_pf);
}
