/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_octa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:39:58 by pelease           #+#    #+#             */
/*   Updated: 2020/02/09 21:39:59 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		with_out_flags(int *len, t_arg *arg, t_fpf *ft_pf)
{
	if (ft_pf->flags[0] != '1')
	{
		ft_putstr(arg->size_w);
		ft_putstr(arg->size_pr);
		ft_putstr(arg->str);
		*len = *len + ft_strlen(arg->size_w) + ft_strlen(arg->size_pr)
			+ ft_strlen(arg->str);
	}
	else
	{
		ft_putstr(arg->size_pr);
		ft_putstr(arg->str);
		ft_putstr(arg->size_w);
		*len = *len + ft_strlen(arg->size_w) + ft_strlen(arg->size_pr)
			+ ft_strlen(arg->str);
	}
}

static void		with_out_flags2(int *len, t_arg *arg, t_fpf *ft_pf)
{
	if (ft_pf->flags[0] != '1')
	{
		ft_putstr(arg->size_w);
		ft_putchar('0');
		ft_putstr(arg->size_pr);
		ft_putstr(arg->str);
		*len = *len + ft_strlen(arg->size_w) + ft_strlen(arg->size_pr)
			+ 1 + ft_strlen(arg->str);
	}
	else
	{
		ft_putchar('0');
		ft_putstr(arg->size_pr);
		ft_putstr(arg->str);
		ft_putstr(arg->size_w);
		*len = *len + ft_strlen(arg->size_w) + ft_strlen(arg->size_pr)
			+ 1 + ft_strlen(arg->str);
	}
}

static void		flag_hash_octa(int *len, t_arg *arg, t_fpf *ft_pf)
{
	if ((ft_pf->flags[3] == '1' && ft_pf->mwidth > 0 && ft_pf->pr_sign == 'N')
		|| ft_pf->precision > 0 || (arg->num_u == 0 && ft_pf->precision == 0
		&& ft_pf->pr_sign == 'N'))
		with_out_flags(len, arg, ft_pf);
	else
		with_out_flags2(len, arg, ft_pf);
}

void			octa_not_minus_side(int *len, t_arg *arg, t_fpf *ft_pf)
{
	int			i;

	i = 0;
	if (ft_pf->flags[3] == '1' && ft_pf->pr_sign != 'Y')
	{
		while (arg->size_w[i] != '\0')
			arg->size_w[i++] = '0';
		(ft_pf->flags[2] == '1') ?
		flag_hash_octa(len, arg, ft_pf) : with_out_flags(len, arg, ft_pf);
	}
	else
		(ft_pf->flags[2] == '1') ?
		flag_hash_octa(len, arg, ft_pf) : with_out_flags(len, arg, ft_pf);
}

void			octa_minus_side(int *len, t_arg *arg, t_fpf *ft_pf)
{
	if (ft_pf->flags[2] == '1')
		flag_hash_octa(len, arg, ft_pf);
	else
		with_out_flags(len, arg, ft_pf);
}
