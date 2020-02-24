/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:39:31 by pelease           #+#    #+#             */
/*   Updated: 2020/02/09 21:39:32 by pelease          ###   ########.fr       */
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

static void		if_zero_flag(t_arg *arg, t_fpf *ft_pf)
{
	if (ft_pf->flags[3] == '1' && ft_pf->pr_sign != 'Y')
	{
		(ft_pf->type == 'x') ? ft_putstr("0x\0") : ft_putstr("0X\0");
		ft_putstr(arg->size_w);
		ft_putstr(arg->size_pr);
		ft_putstr(arg->str);
	}
	else
	{
		ft_putstr(arg->size_w);
		(ft_pf->type == 'x') ? ft_putstr("0x\0") : ft_putstr("0X\0");
		ft_putstr(arg->size_pr);
		ft_putstr(arg->str);
	}
}

static void		with_out_flags2(int *len, t_arg *arg, t_fpf *ft_pf)
{
	if (ft_pf->flags[0] != '1')
	{
		if_zero_flag(arg, ft_pf);
		*len = *len + ft_strlen(arg->size_w) + ft_strlen(arg->size_pr)
			+ 2 + ft_strlen(arg->str);
	}
	else
	{
		if (ft_pf->type == 'x')
			ft_putstr("0x\0");
		else
			ft_putstr("0X\0");
		ft_putstr(arg->size_pr);
		ft_putstr(arg->str);
		ft_putstr(arg->size_w);
		*len = *len + ft_strlen(arg->size_w) + ft_strlen(arg->size_pr)
			+ 2 + ft_strlen(arg->str);
	}
}

void			hex_not_minus_side(int *len, t_arg *arg, t_fpf *ft_pf)
{
	int			i;

	i = 0;
	if (ft_pf->flags[3] == '1' && ft_pf->pr_sign != 'Y')
	{
		while (arg->size_w[i] != '\0')
			arg->size_w[i++] = '0';
		if (ft_pf->flags[2] == '1')
			(arg->num_u == 0) ? with_out_flags(len, arg, ft_pf) :
			with_out_flags2(len, arg, ft_pf);
		else
			with_out_flags(len, arg, ft_pf);
	}
	else
	{
		if (ft_pf->flags[2] == '1')
			(arg->num_u == 0) ? with_out_flags(len, arg, ft_pf) :
			with_out_flags2(len, arg, ft_pf);
		else
			with_out_flags(len, arg, ft_pf);
	}
}

void			hex_minus_side(int *len, t_arg *arg, t_fpf *ft_pf)
{
	if (ft_pf->flags[2] == '1')
	{
		if (arg->num_u == 0)
			with_out_flags(len, arg, ft_pf);
		else
			with_out_flags2(len, arg, ft_pf);
	}
	else
		with_out_flags(len, arg, ft_pf);
}
