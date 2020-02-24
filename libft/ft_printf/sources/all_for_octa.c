/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_for_octa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:37:19 by pelease           #+#    #+#             */
/*   Updated: 2020/02/09 21:37:22 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void			octa_type_and_modf(va_list ap, t_fpf *ft_pf, t_arg *arg)
{
	int			i;

	i = 4;
	while (--i >= 0)
	{
		if (ft_pf->modf[i] == '1')
			break ;
	}
	if (i != -1)
	{
		if (i == 0)
			arg->num_u = (unsigned char)va_arg(ap, int);
		else if (i == 1)
			arg->num_u = (unsigned short)va_arg(ap, int);
		else if (i == 2)
			arg->num_u = va_arg(ap, unsigned long);
		else if (i == 3)
			arg->num_u = va_arg(ap, unsigned long long);
	}
	else
		arg->num_u = va_arg(ap, unsigned int);
	ft_uitoa_printf(ft_pf, arg);
}

void			octa_mwidth(t_fpf *ft_pf, t_arg *arg)
{
	int			i;
	int			tmp;

	i = -1;
	tmp = 0;
	if (ft_pf->flags[2] == '1' && !((ft_pf->flags[3] == '1' && ft_pf->mwidth > 0
		&& ft_pf->pr_sign == 'N') || ft_pf->precision > 0 || (arg->num_u == 0 &&
		ft_pf->precision == 0 && ft_pf->pr_sign == 'N')))
		tmp = 1;
	ft_pf->mwidth = (ft_pf->mwidth > arg->strlen + ft_pf->precision) ?
		ft_pf->mwidth - (arg->strlen + tmp + ft_pf->precision) : 0;
	if (ft_pf->mwidth > 0)
	{
		if (!(arg->size_w = (char*)malloc(sizeof(char) * (ft_pf->mwidth + 1))))
			exit(1);
		while (++i < ft_pf->mwidth)
			arg->size_w[i] = ' ';
		arg->size_w[ft_pf->mwidth] = '\0';
	}
	else
	{
		if (!(arg->size_w = (char*)malloc(sizeof(char))))
			exit(1);
		arg->size_w[0] = '\0';
	}
}

void			octa_flags(t_fpf *ft_pf, t_arg *arg, int *len)
{
	if (ft_pf->flags[0] == '1')
		octa_minus_side(len, arg, ft_pf);
	else
		octa_not_minus_side(len, arg, ft_pf);
}
