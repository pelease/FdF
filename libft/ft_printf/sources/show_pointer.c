/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:40:04 by pelease           #+#    #+#             */
/*   Updated: 2020/02/09 21:40:06 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		flag_zero(t_arg *arg, t_fpf *ft_pf)
{
	if (ft_pf->flags[3] == '1' && ft_pf->pr_sign != 'Y')
	{
		ft_putstr("0x\0");
		ft_putstr(arg->size_w);
		ft_putstr(arg->size_pr);
	}
	else if (ft_pf->precision == 0 && ft_pf->pr_sign == 'Y')
	{
		ft_putstr(arg->size_w);
		ft_putstr("0x\0");
		ft_putstr(arg->size_pr);
	}
	else if (ft_pf->pr_sign == 'Y')
	{
		ft_putstr(arg->size_w);
		ft_putstr("0x0\0");
		ft_putstr(arg->size_pr);
	}
	else
	{
		ft_putstr(arg->size_w);
		ft_putstr("0x0\0");
	}
}

static void		only_zero(int *len, t_arg *arg, t_fpf *ft_pf)
{
	if (ft_pf->flags[0] != '1')
		flag_zero(arg, ft_pf);
	else
	{
		if (ft_pf->precision == 0 && ft_pf->pr_sign == 'Y')
		{
			ft_putstr("0x\0");
			ft_putstr(arg->size_pr);
			ft_putstr(arg->size_w);
		}
		else if (ft_pf->pr_sign == 'Y')
		{
			ft_putstr(arg->size_w);
			ft_putstr("0x0\0");
			ft_putstr(arg->size_pr);
		}
		else
		{
			ft_putstr("0x0\0");
			ft_putstr(arg->size_w);
		}
	}
	*len = *len + ft_strlen(arg->size_w) + ft_strlen(arg->size_pr)
			+ 2 + ft_strlen(arg->str);
}

static void		not_zero(int *len, t_arg *arg, t_fpf *ft_pf)
{
	if (ft_pf->flags[0] != '1')
	{
		if (ft_pf->flags[3] == '1' && ft_pf->pr_sign != 'Y')
		{
			ft_putstr("0x\0");
			ft_putstr(arg->size_w);
		}
		else
		{
			ft_putstr(arg->size_w);
			ft_putstr("0x\0");
		}
		ft_putstr(arg->size_pr);
		ft_putstr(arg->str);
	}
	else
	{
		ft_putstr("0x\0");
		ft_putstr(arg->size_pr);
		ft_putstr(arg->str);
		ft_putstr(arg->size_w);
	}
	*len = *len + ft_strlen(arg->size_w) + ft_strlen(arg->size_pr)
		+ 2 + ft_strlen(arg->str);
}

void			pointer_not_minus_side(int *len, t_arg *arg, t_fpf *ft_pf)
{
	int			i;

	i = 0;
	if (ft_pf->flags[3] == '1' && ft_pf->pr_sign != 'Y')
	{
		while (arg->size_w[i] != '\0')
			arg->size_w[i++] = '0';
		if (arg->num_u == 0)
			only_zero(len, arg, ft_pf);
		else
			not_zero(len, arg, ft_pf);
	}
	else
	{
		if (arg->num_u == 0)
			only_zero(len, arg, ft_pf);
		else
			not_zero(len, arg, ft_pf);
	}
}

void			pointer_minus_side(int *len, t_arg *arg, t_fpf *ft_pf)
{
	if (arg->num_u == 0)
		only_zero(len, arg, ft_pf);
	else
		not_zero(len, arg, ft_pf);
}
