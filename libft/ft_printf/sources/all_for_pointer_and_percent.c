/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_for_pointer_and_percent.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:38:07 by pelease           #+#    #+#             */
/*   Updated: 2020/02/09 21:38:10 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void			pointer_type(va_list ap, t_fpf *ft_pf, t_arg *arg)
{
	arg->num_u = va_arg(ap, unsigned long long int);
	ft_uitoa_printf(ft_pf, arg);
}

void			pointer_mwidth(t_fpf *ft_pf, t_arg *arg)
{
	int			i;
	int			tmp;

	i = -1;
	tmp = 2;
	ft_pf->mwidth = (ft_pf->mwidth > arg->strlen + ft_pf->precision + tmp) ?
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

void			pointer_flags(t_fpf *ft_pf, t_arg *arg, int *len)
{
	if (ft_pf->flags[0] == '1')
		pointer_minus_side(len, arg, ft_pf);
	else
		pointer_not_minus_side(len, arg, ft_pf);
}

void			percent_mwidth(t_fpf *ft_pf, t_arg *arg)
{
	int			i;

	i = -1;
	ft_pf->mwidth = (ft_pf->mwidth > 1) ? ft_pf->mwidth - 1 : 0;
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

void			percent_flags(t_fpf *ft_pf, t_arg *arg, int *len)
{
	int			i;

	i = 0;
	if (ft_pf->flags[0] != '1')
	{
		if (ft_pf->flags[3] == '1')
		{
			while (arg->size_w[i] != '\0')
				arg->size_w[i++] = '0';
		}
		ft_putstr(arg->size_w);
		ft_putchar('%');
		*len = *len + ft_strlen(arg->size_w) + 1;
	}
	else
	{
		ft_putchar('%');
		ft_putstr(arg->size_w);
		*len = *len + ft_strlen(arg->size_w) + 1;
	}
}
