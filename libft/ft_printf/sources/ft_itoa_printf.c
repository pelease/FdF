/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:01:02 by pelease           #+#    #+#             */
/*   Updated: 2020/01/29 16:01:05 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static long long	delete_size(t_arg arg)
{
	long long		i;

	i = 1;
	while (arg.num_di <= -10 || arg.num_di >= 10)
	{
		arg.num_di /= 10;
		i *= 10;
	}
	return (i);
}

static int			str_size(t_arg arg, t_fpf *ft_pf)
{
	int				i;

	i = 0;
	if (arg.num_di == 0 && ft_pf->pr_sign == 'Y' && ft_pf->precision == 0
		&& ft_pf->type != 'f')
		return (0);
	if (arg.num_di == 0)
		i++;
	while (arg.num_di != 0)
	{
		arg.num_di /= 10;
		i++;
	}
	return (i);
}

static int			itoa_output(t_arg *arg, t_fpf *ft_pf, long long del_size)
{
	int				s_size;
	long long		num;

	s_size = 0;
	if (arg->num_di < 0)
		arg->num_di = arg->num_di * (-1);
	num = arg->num_di;
	if (num == 0 && ft_pf->pr_sign == 'Y' && ft_pf->precision == 0
		&& ft_pf->type != 'f')
		return (0);
	while (del_size > 0)
	{
		arg->str[s_size] = (num / del_size) % 10 + '0';
		s_size++;
		del_size /= 10;
	}
	return (s_size);
}

void				ft_itoa_printf(t_fpf *ft_pf, t_arg *arg)
{
	int				a;
	int				s_size;
	long long		del_size;

	del_size = delete_size(*arg);
	a = 0;
	arg->str = (char*)malloc(sizeof(char) * (str_size(*arg, ft_pf) + 1));
	if (!arg->str)
		exit(1);
	if (arg->num_di == LLONG_MIN)
	{
		arg->num_di += 1;
		a = 1;
	}
	s_size = itoa_output(arg, ft_pf, del_size);
	if (a == 1)
		arg->str[s_size - 1] = '8';
	arg->str[s_size] = '\0';
	arg->strlen = ft_strlen(arg->str);
}
