/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_execution_part2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:40:33 by pelease           #+#    #+#             */
/*   Updated: 2020/02/09 21:40:38 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void			percent_execution(int *len, t_fpf *ft_pf)
{
	t_arg		arg;

	percent_mwidth(ft_pf, &arg);
	percent_flags(ft_pf, &arg, len);
	ft_strdel(&arg.size_w);
}

void			char_execution(va_list ap, int *len, t_fpf *ft_pf)
{
	t_arg		arg;

	char_type_and_mwidth(ap, ft_pf, &arg);
	char_flags(ft_pf, &arg, len);
	ft_strdel(&arg.size_w);
}

void			string_execution(va_list ap, int *len, t_fpf *ft_pf)
{
	t_arg		arg;

	string_type_precision(ap, ft_pf, &arg);
	string_mwidth(ft_pf, &arg);
	string_flags(ft_pf, &arg, len);
	ft_strdel(&arg.size_w);
}

void			float_execution(va_list ap, int *len, t_fpf *ft_pf)
{
	t_arg		arg;

	float_left_side(ap, ft_pf, &arg, len);
	if (arg.nan_inf == 0)
	{
		float_right_side(ft_pf, &arg);
		float_mwidth(ft_pf, &arg);
		float_flags(ft_pf, &arg, len);
		ft_strdel(&arg.size_w);
		ft_strdel(&arg.str);
	}
}
