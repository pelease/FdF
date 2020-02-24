/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_for_int_uint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 22:56:38 by pelease           #+#    #+#             */
/*   Updated: 2020/02/05 22:56:52 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void			int_type_and_modf(va_list ap, t_fpf *ft_pf, t_arg *arg)
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
			arg->num_di = (char)va_arg(ap, int);
		else if (i == 1)
			arg->num_di = (short)va_arg(ap, int);
		else if (i == 2)
			arg->num_di = va_arg(ap, long);
		else if (i == 3)
			arg->num_di = va_arg(ap, long long);
	}
	else
		arg->num_di = va_arg(ap, int);
	arg->sign = (arg->num_di < 0) ? '-' : '+';
	ft_itoa_printf(ft_pf, arg);
}

void			uint_type_and_modf(va_list ap, t_fpf *ft_pf, t_arg *arg)
{
	int			i;

	i = 4;
	arg->sign = '+';
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

void			int_precision(t_fpf *ft_pf, t_arg *arg)
{
	int			i;

	i = -1;
	if (arg->str[0] == '-')
		arg->strlen -= 1;
	if (ft_pf->precision > 0 && ft_pf->precision > arg->strlen)
	{
		ft_pf->precision -= arg->strlen;
		if (!(arg->size_pr = (char*)malloc(sizeof(char) *
			(ft_pf->precision + 1))))
			exit(1);
		while (++i < ft_pf->precision)
			arg->size_pr[i] = '0';
		arg->size_pr[ft_pf->precision] = '\0';
	}
	else
	{
		if (!(arg->size_pr = (char*)malloc(sizeof(char))))
			exit(1);
		arg->size_pr[0] = '\0';
		ft_pf->precision = 0;
	}
	if (arg->str[0] == '-')
		arg->strlen += 1;
}

void			int_mwidth(t_fpf *ft_pf, t_arg *arg)
{
	int			i;
	int			tmp;

	i = -1;
	tmp = (arg->sign == '-') ? 1 : 0;
	if (((arg->sign == '+' && ft_pf->flags[1] == '1') || (ft_pf->flags[4] == '1'
		&& ft_pf->flags[0] == '1')) && ft_pf->type != 'u')
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

void			int_flags(t_fpf *ft_pf, t_arg *arg, int *len)
{
	if (ft_pf->flags[0] != '1')
		int_uint_not_minus_side(len, arg, ft_pf);
	else
		int_uint_minus_side(len, arg, ft_pf);
}
