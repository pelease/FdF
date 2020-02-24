/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:06:59 by pelease           #+#    #+#             */
/*   Updated: 2020/01/21 13:07:01 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;
	char		*f;

	f = (char*)format;
	len = 0;
	va_start(ap, format);
	while (*f)
	{
		if (*f == '%')
		{
			f++;
			if (buffer(&f, ap, &len) == 0)
				break ;
		}
		else
		{
			write(1, f, 1);
			len++;
		}
		f++;
	}
	va_end(ap);
	return (len);
}

static void		init_data(t_fpf *ft_pf)
{
	int			i;

	i = -1;
	ft_pf->mwidth = 0;
	ft_pf->precision = 0;
	while (++i < 5)
		ft_pf->flags[i] = '0';
	ft_pf->flags[5] = '\0';
	ft_pf->pr_sign = 'N';
	i = -1;
	while (++i < 5)
		ft_pf->modf[i] = '0';
	ft_pf->modf[5] = '\0';
}

int				buffer(char **f, va_list ap, int *len)
{
	t_fpf		ft_pf;

	init_data(&ft_pf);
	while (**f != '\0')
	{
		if (**f == '-' || **f == '+' || **f == '#' || **f == '0' || **f == ' ')
			flags_option(f, &ft_pf);
		else if ((**f >= '1' && **f <= '9') || **f == '*')
			mwidth_option(ap, f, &ft_pf);
		else if (**f == '.')
			precision_option(ap, f, &ft_pf);
		else if (**f == 'h' || **f == 'l' || **f == 'L')
			modf_option(f, &ft_pf);
		else if (**f == 'd' || **f == 'i' || **f == 'o' || **f == 'u' ||
				**f == 'x' || **f == 'X' || **f == 'f' || **f == 'c' ||
				**f == 's' || **f == 'p' || **f == '%')
		{
			type_option(f, ap, len, &ft_pf);
			return (1);
		}
		else
			(*f)++;
	}
	return (0);
}
