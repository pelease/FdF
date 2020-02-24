/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_for_char_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:37:00 by pelease           #+#    #+#             */
/*   Updated: 2020/02/09 21:37:03 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void			char_type_and_mwidth(va_list ap, t_fpf *ft_pf, t_arg *arg)
{
	int			i;

	arg->num_di = (char)va_arg(ap, int);
	i = -1;
	ft_pf->mwidth = (ft_pf->mwidth > 1) ? (ft_pf->mwidth - 1) : 0;
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

void			char_flags(t_fpf *ft_pf, t_arg *arg, int *len)
{
	if (ft_pf->flags[0] != '1')
	{
		ft_putstr(arg->size_w);
		ft_putchar(arg->num_di);
		*len = *len + ft_strlen(arg->size_w) + 1;
	}
	else
	{
		ft_putchar(arg->num_di);
		ft_putstr(arg->size_w);
		*len = *len + ft_strlen(arg->size_w) + 1;
	}
}

void			string_type_precision(va_list ap, t_fpf *ft_pf, t_arg *arg)
{
	arg->str = va_arg(ap, char *);
	if (arg->str != NULL)
	{
		arg->strlen = ft_strlen(arg->str);
		if (ft_pf->precision > 0 && ft_pf->precision > arg->strlen)
			ft_pf->precision = arg->strlen;
		else if (ft_pf->precision == 0 && ft_pf->pr_sign == 'N')
			ft_pf->precision = arg->strlen;
	}
	else
	{
		if (ft_pf->precision > 0 && ft_pf->precision > 6)
			ft_pf->precision = 6;
		else if (ft_pf->precision == 0 && ft_pf->pr_sign == 'N')
			ft_pf->precision = 6;
	}
}

void			string_mwidth(t_fpf *ft_pf, t_arg *arg)
{
	int			i;

	i = -1;
	ft_pf->mwidth = (ft_pf->mwidth > ft_pf->precision) ?
					(ft_pf->mwidth - ft_pf->precision) : 0;
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

void			string_flags(t_fpf *ft_pf, t_arg *arg, int *len)
{
	int			i;
	char		*a;

	if (!(a = ft_strdup("(null)\0")))
		exit(1);
	i = 0;
	if (ft_pf->flags[0] != '1')
		ft_putstr(arg->size_w);
	if (arg->str == NULL)
	{
		while (a[i] != '\0' && i < ft_pf->precision)
			ft_putchar(a[i++]);
	}
	else
	{
		while (arg->str[i] != '\0' && i < ft_pf->precision)
			ft_putchar(arg->str[i++]);
	}
	if (ft_pf->flags[0] == '1')
		ft_putstr(arg->size_w);
	*len = *len + ft_strlen(arg->size_w) + ft_pf->precision;
	ft_strdel(&a);
}
