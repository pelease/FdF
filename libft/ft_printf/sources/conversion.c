/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:37:11 by pelease           #+#    #+#             */
/*   Updated: 2020/01/23 21:37:18 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void					uint_conversion(t_arg *arg)
{
	int						i;

	i = arg->strlen - 1;
	if (!(arg->str = (char*)malloc(sizeof(char) * (arg->strlen + 1))))
		exit(1);
	arg->str[arg->strlen] = '\0';
	while (i >= 0)
	{
		arg->str[i--] = (arg->num_u % 10) + '0';
		arg->num_u /= 10;
	}
}

static void					octa_conversion(t_arg *arg)
{
	int						i;
	unsigned long long		num;

	num = arg->num_u;
	i = arg->strlen - 1;
	if (!(arg->str = (char*)malloc(sizeof(char) * (arg->strlen + 1))))
		exit(1);
	arg->str[arg->strlen] = '\0';
	while (i >= 0)
	{
		arg->str[i--] = (num % 8) + '0';
		num /= 8;
	}
}

static void					hex_conversion(t_arg *arg, t_fpf *ft_pf)
{
	char					*str;
	char					*cap_str;
	int						i;
	unsigned long long		num;

	if (!(str = ft_strdup("0123456789abcdef\0")))
		exit(1);
	if (!(cap_str = ft_strdup("0123456789ABCDEF\0")))
		exit(1);
	i = arg->strlen - 1;
	num = arg->num_u;
	if (!(arg->str = (char*)malloc(sizeof(char) * (arg->strlen + 1))))
		exit(1);
	arg->str[arg->strlen] = '\0';
	while (i >= 0)
	{
		if (ft_pf->type == 'x' || ft_pf->type == 'p')
			arg->str[i--] = str[num % 16];
		else
			arg->str[i--] = cap_str[num % 16];
		num /= 16;
	}
	ft_strdel(&str);
	ft_strdel(&cap_str);
}

void						all_conversion(t_arg *arg, t_fpf *ft_pf)
{
	if (ft_pf->type == 'o')
		octa_conversion(arg);
	else if (ft_pf->type == 'x' || ft_pf->type == 'X' || ft_pf->type == 'p')
		hex_conversion(arg, ft_pf);
	else
		uint_conversion(arg);
}
