/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_float_part2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:58:30 by pelease           #+#    #+#             */
/*   Updated: 2020/02/09 21:58:33 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		float_sign_space(int *len, t_arg *arg, t_fpf *ft_pf, int test)
{
	ft_putchar(arg->sign);
	ft_putstr(arg->str);
	if ((test = (ft_pf->precision > 0 || (ft_pf->precision == 0
		&& ft_pf->flags[2] == '1'))) == 1)
		ft_putchar('.');
	ft_putstr(arg->f);
	ft_putstr(arg->size_w);
	*len = *len + ft_strlen(arg->size_w) + ft_strlen(arg->f)
		+ 1 + test + ft_strlen(arg->str);
}

void			float_minus_side(int *len, t_arg *arg, t_fpf *ft_pf, int test)
{
	if (ft_pf->flags[1] == '1' || (ft_pf->flags[1] != '1'
			&& arg->sign == '-'))
		float_sign_space(len, arg, ft_pf, test);
	else if (ft_pf->flags[4] == '1')
	{
		ft_putchar(' ');
		ft_putstr(arg->str);
		if ((test = (ft_pf->precision > 0 || (ft_pf->precision == 0
			&& ft_pf->flags[2] == '1'))) == 1)
			ft_putchar('.');
		ft_putstr(arg->f);
		ft_putstr(arg->size_w);
		*len = *len + ft_strlen(arg->size_w) + ft_strlen(arg->f)
			+ test + ft_strlen(arg->str);
	}
	else
		float_flag_hash(len, arg, ft_pf);
}

int				float_nan_inf(int *len, t_arg *arg, t_fpf *ft_pf)
{
	int			i;

	i = 0;
	if (arg->num_fl != arg->num_fl)
		i = 1;
	if ((arg->num_fl == arg->num_fl + arg->num_fl / .0) && arg->num_fl > 0)
		i = (ft_pf->flags[1] == '1') ? 4 : 3;
	if ((arg->num_fl == arg->num_fl + arg->num_fl / .0) && arg->num_fl < 0)
		i = 2;
	if (i == 1 || i == 3)
		*len += 3;
	else if (i == 2 || i == 4)
		*len += 4;
	if (i == 1)
		ft_putstr("nan");
	else if (i == 4)
		ft_putstr("+inf");
	else if (i == 3)
		ft_putstr("inf");
	else if (i == 2)
		ft_putstr("-inf");
	return (i);
}
