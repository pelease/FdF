/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:39:22 by pelease           #+#    #+#             */
/*   Updated: 2020/02/09 21:39:26 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void			float_flag_hash(int *len, t_arg *arg, t_fpf *ft_pf)
{
	if (ft_pf->flags[0] != '1')
	{
		ft_putstr(arg->size_w);
		ft_putstr(arg->str);
		if (ft_pf->precision > 0 ||
			(ft_pf->precision == 0 && ft_pf->flags[2] == '1'))
			ft_putchar('.');
		ft_putstr(arg->f);
		*len = *len + ft_strlen(arg->size_w) + ft_strlen(arg->f)
			+ ft_strlen(arg->str);
	}
	else
	{
		ft_putstr(arg->str);
		if (ft_pf->precision > 0 ||
			(ft_pf->precision == 0 && ft_pf->flags[2] == '1'))
			ft_putchar('.');
		ft_putstr(arg->f);
		ft_putstr(arg->size_w);
		*len = *len + ft_strlen(arg->size_w) + ft_strlen(arg->f)
			+ ft_strlen(arg->str);
	}
	if (ft_pf->precision > 0 ||
			(ft_pf->precision == 0 && ft_pf->flags[2] == '1'))
		*len += 1;
}

static void		flag_space(int *len, t_arg *arg, t_fpf *ft_pf)
{
	if (ft_pf->mwidth == 0)
	{
		ft_putchar(' ');
		*len = *len + ft_strlen(arg->size_w) +
			ft_strlen(arg->f) + 1 + ft_strlen(arg->str);
	}
	else
	{
		arg->size_w[0] = ' ';
		*len = *len + ft_strlen(arg->size_w) +
			ft_strlen(arg->f) + ft_strlen(arg->str);
	}
	ft_putstr(arg->size_w);
	ft_putstr(arg->str);
	if (ft_pf->precision > 0 ||
			(ft_pf->precision == 0 && ft_pf->flags[2] == '1'))
	{
		ft_putchar('.');
		*len += 1;
	}
	ft_putstr(arg->f);
}

static void		flag_zero_space_sign(int *len, t_arg *arg, t_fpf *ft_pf)
{
	if (ft_pf->flags[1] == '1' || (ft_pf->flags[1] != '1'
		&& arg->sign == '-'))
	{
		ft_putchar(arg->sign);
		ft_putstr(arg->size_w);
		ft_putstr(arg->str);
		if (ft_pf->precision > 0 ||
			(ft_pf->precision == 0 && ft_pf->flags[2] == '1'))
		{
			ft_putchar('.');
			*len += 1;
		}
		ft_putstr(arg->f);
		*len = *len + ft_strlen(arg->size_w) + ft_strlen(arg->f)
			+ 1 + ft_strlen(arg->str);
	}
	else if (ft_pf->flags[4] == '1')
		flag_space(len, arg, ft_pf);
	else
		float_flag_hash(len, arg, ft_pf);
}

static void		flags_for_not_minus(int *len, t_arg *arg, t_fpf *ft_pf,
				int test)
{
	ft_putstr(arg->size_w);
	ft_putchar(arg->sign);
	ft_putstr(arg->str);
	if ((test = (ft_pf->precision > 0 || (ft_pf->precision == 0
		&& ft_pf->flags[2] == '1'))) == 1)
		ft_putchar('.');
	ft_putstr(arg->f);
	*len = *len + ft_strlen(arg->size_w) + ft_strlen(arg->f)
		+ 1 + test + ft_strlen(arg->str);
}

void			float_not_minus_side(int *len, t_arg *arg, t_fpf *ft_pf,
				int test)
{
	int			i;

	i = 0;
	if (ft_pf->flags[3] == '1')
	{
		while (arg->size_w[i] != '\0')
			arg->size_w[i++] = '0';
		flag_zero_space_sign(len, arg, ft_pf);
	}
	else if (ft_pf->flags[1] == '1' || (ft_pf->flags[1] != '1'
		&& arg->sign == '-'))
		flags_for_not_minus(len, arg, ft_pf, test);
	else if (ft_pf->flags[4] == '1')
		flag_space(len, arg, ft_pf);
	else
		float_flag_hash(len, arg, ft_pf);
}
