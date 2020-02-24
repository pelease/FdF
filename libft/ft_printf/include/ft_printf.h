/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:52:10 by pelease           #+#    #+#             */
/*   Updated: 2020/01/22 14:56:46 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PREC 			precision

# include <limits.h>
# include "../../libft/include/libft.h"
# include <stdarg.h>

typedef struct			s_fpf
{
	char				flags[6];
	int					mwidth;
	char				pr_sign;
	int					precision;
	char				modf[6];
	char				type;
}						t_fpf;

typedef struct			s_arg
{
	char				*size_w;
	char				*size_pr;
	long long			num_di;
	unsigned long long	num_u;
	int					strlen;
	char				*str;
	char				sign;
	long double			num_fl;
	int					nan_inf;
	char				f[51];
}						t_arg;

int						ft_printf(const char *format, ...);
int						buffer(char **f, va_list ap, int *len);

void					flags_option(char **f, t_fpf *ft_pf);
void					mwidth_option(va_list ap, char **f, t_fpf *ft_pf);
void					precision_option(va_list ap, char **f, t_fpf *ft_pf);
void					modf_option(char **f, t_fpf *ft_pf);
void					type_option(char **f, va_list ap, int *len,
						t_fpf *ft_pf);

void					int_execution(va_list ap, int *len, t_fpf *ft_pf);
void					uint_execution(va_list ap, int *len, t_fpf *ft_pf);
void					octa_execution(va_list ap, int *len, t_fpf *ft_pf);
void					hex_execution(va_list ap, int *len, t_fpf *ft_pf);
void					pointer_execution(va_list ap, int *len, t_fpf *ft_pf);
void					percent_execution(int *len, t_fpf *ft_pf);
void					char_execution(va_list ap, int *len, t_fpf *ft_pf);
void					string_execution(va_list ap, int *len, t_fpf *ft_pf);
void					float_execution(va_list ap, int *len, t_fpf *ft_pf);

void					int_type_and_modf(va_list ap, t_fpf *ft_pf, t_arg *arg);
void					int_mwidth(t_fpf *ft_pf, t_arg *arg);
void					int_precision(t_fpf *ft_pf, t_arg *arg);
void					int_flags(t_fpf *ft_pf, t_arg *arg, int *len);

void					uint_type_and_modf(va_list ap, t_fpf *ft_pf,
						t_arg *arg);
void					octa_type_and_modf(va_list ap, t_fpf *ft_pf,
						t_arg *arg);
void					octa_mwidth(t_fpf *ft_pf, t_arg *arg);
void					octa_flags(t_fpf *ft_pf, t_arg *arg, int *len);

void					hex_type_and_modf(va_list ap, t_fpf *ft_pf, t_arg *arg);
void					hex_mwidth(t_fpf *ft_pf, t_arg *arg);
void					hex_flags(t_fpf *ft_pf, t_arg *arg, int *len);

void					pointer_type(va_list ap, t_fpf *ft_pf, t_arg *arg);
void					pointer_mwidth(t_fpf *ft_pf, t_arg *arg);
void					pointer_flags(t_fpf *ft_pf, t_arg *arg, int *len);

void					percent_mwidth(t_fpf *ft_pf, t_arg *arg);
void					percent_flags(t_fpf *ft_pf, t_arg *arg, int *len);

void					char_type_and_mwidth(va_list ap, t_fpf *ft_pf,
						t_arg *arg);
void					char_flags(t_fpf *ft_pf, t_arg *arg, int *len);

void					string_type_precision(va_list ap, t_fpf *ft_pf,
						t_arg *arg);
void					string_mwidth(t_fpf *ft_pf, t_arg *arg);
void					string_flags(t_fpf *ft_pf, t_arg *arg, int *len);

void					float_left_side(va_list ap, t_fpf *ft_pf, t_arg *arg,
						int *len);
void					float_right_side(t_fpf *ft_pf, t_arg *arg);
int						float_nan_inf(int *len, t_arg *arg, t_fpf *ft_pf);
void					float_mwidth(t_fpf *ft_pf, t_arg *arg);
void					float_flags(t_fpf *ft_pf, t_arg *arg, int *len);

void					int_uint_minus_side(int *len, t_arg *arg, t_fpf *ft_pf);
void					int_uint_not_minus_side(int *len, t_arg *arg,
						t_fpf *ft_pf);

void					octa_not_minus_side(int *len, t_arg *arg, t_fpf *ft_pf);
void					octa_minus_side(int *len, t_arg *arg, t_fpf *ft_pf);

void					hex_not_minus_side(int *len, t_arg *arg, t_fpf *ft_pf);
void					hex_minus_side(int *len, t_arg *arg, t_fpf *ft_pf);

void					pointer_minus_side(int *len, t_arg *arg, t_fpf *ft_pf);
void					pointer_not_minus_side(int *len, t_arg *arg,
						t_fpf *ft_pf);

void					float_minus_side(int *len, t_arg *arg, t_fpf *ft_pf,
						int test);
void					float_not_minus_side(int *len, t_arg *arg, t_fpf *ft_pf,
						int test);
void					float_flag_hash(int *len, t_arg *arg, t_fpf *ft_pf);

void					ft_itoa_printf(t_fpf *ft_pf, t_arg *arg);
void					ft_uitoa_printf(t_fpf *ft_pf, t_arg *arg);

void					asterisk_mwidth(va_list ap, char **f, t_fpf *ft_pf);
void					asterisk_precision(va_list ap, char **f, t_fpf *ft_pf);

void					all_conversion(t_arg *arg, t_fpf *ft_pf);

#endif
