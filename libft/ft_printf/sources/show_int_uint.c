/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_int_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:31:45 by pelease           #+#    #+#             */
/*   Updated: 2020/02/05 19:31:47 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		without_flags(int *len, t_arg *arg, t_fpf *ft_pf)
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

static void		flag_space(int *len, t_arg *arg, t_fpf *ft_pf)
{
	if (ft_pf->mwidth == 0)
	{
		ft_putchar(' ');
		*len = *len + ft_strlen(arg->size_w) +
			ft_strlen(arg->size_pr) + 1 + ft_strlen(arg->str);
	}
	else
	{
		arg->size_w[0] = ' ';
		*len = *len + ft_strlen(arg->size_w) +
			ft_strlen(arg->size_pr) + ft_strlen(arg->str);
	}
	ft_putstr(arg->size_w);
	ft_putstr(arg->size_pr);
	ft_putstr(arg->str);
}

static void		flag_zero_space_sign(int *len, t_arg *arg, t_fpf *ft_pf)
{
	if ((ft_pf->flags[1] == '1' || (ft_pf->flags[1] != '1'
		&& arg->sign == '-')) && ft_pf->type != 'u')
	{
		ft_putchar(arg->sign);
		ft_putstr(arg->size_w);
		ft_putstr(arg->size_pr);
		ft_putstr(arg->str);
		*len = *len + ft_strlen(arg->size_w) + ft_strlen(arg->size_pr)
			+ 1 + ft_strlen(arg->str);
	}
	else if (ft_pf->flags[4] == '1' && ft_pf->type != 'u')
		flag_space(len, arg, ft_pf);
	else
		without_flags(len, arg, ft_pf);
}

void			int_uint_not_minus_side(int *len, t_arg *arg, t_fpf *ft_pf)
{
	int			i;

	i = 0;
	if (ft_pf->flags[3] == '1' && ft_pf->pr_sign != 'Y')
	{
		while (arg->size_w[i] != '\0')
			arg->size_w[i++] = '0';
		flag_zero_space_sign(len, arg, ft_pf);
	}
	else if ((ft_pf->flags[1] == '1' || (ft_pf->flags[1] != '1'
		&& arg->sign == '-')) && ft_pf->type != 'u')
	{
		ft_putstr(arg->size_w);
		ft_putchar(arg->sign);
		ft_putstr(arg->size_pr);
		ft_putstr(arg->str);
		*len = *len + ft_strlen(arg->size_w) + ft_strlen(arg->size_pr)
			+ 1 + ft_strlen(arg->str);
	}
	else if (ft_pf->flags[4] == '1' && ft_pf->type != 'u')
		flag_space(len, arg, ft_pf);
	else
		without_flags(len, arg, ft_pf);
}

void			int_uint_minus_side(int *len, t_arg *arg, t_fpf *ft_pf)
{
	if ((ft_pf->flags[1] == '1' || (ft_pf->flags[1] != '1'
			&& arg->sign == '-')) && ft_pf->type != 'u')
	{
		ft_putchar(arg->sign);
		ft_putstr(arg->size_pr);
		ft_putstr(arg->str);
		ft_putstr(arg->size_w);
		*len = *len + ft_strlen(arg->size_w) + ft_strlen(arg->size_pr)
			+ 1 + ft_strlen(arg->str);
	}
	else if (ft_pf->flags[4] == '1' && ft_pf->type != 'u')
	{
		ft_putchar(' ');
		*len = *len + ft_strlen(arg->size_w) + ft_strlen(arg->size_pr)
			+ ft_strlen(arg->str);
		ft_putstr(arg->size_pr);
		ft_putstr(arg->str);
		ft_putstr(arg->size_w);
	}
	else
		without_flags(len, arg, ft_pf);
}
