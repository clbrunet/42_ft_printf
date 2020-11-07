/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 13:13:45 by clbrunet          #+#    #+#             */
/*   Updated: 2020/11/07 11:16:58 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft.h"

typedef struct	s_conv_specs
{
	int		sharp;
	int		zero;
	int		minus;
	int		blank;
	int		plus;
	int		width;
	int		precision;
	int		l;
	int		h;
	int		specifier;
}				t_conv_specs;

int				get_g_res(void);
void			putchar_count(char c);
void			putstr_count(char *s);

int				hexlen(unsigned long long n, int len);

int				nbrlen(unsigned long long n, int len);
void			putnbr_ull_count(unsigned long long n);
int				nbradd_len(int sign, t_conv_specs *specs);

int				round_needed(long double f, int left, unsigned long long nb,
		int precision);
int				is_trailing_zero(long double f, int left);

void			putchar_specs(char c, t_conv_specs *specs);
void			putstr_specs(char *s, t_conv_specs *specs);
void			putptr_specs(unsigned long long n, t_conv_specs *specs);
void			putnbr_specs(unsigned long long n, int sign,
		t_conv_specs *specs);
void			puthex_specs(unsigned long long n, t_conv_specs *specs);
void			putfloat_specs(long double f, int sign, t_conv_specs *specs);
void			putcompactfloat_specs(long double f, int sign,
		t_conv_specs *specs);
void			putexponent_specs(long double f, int sign, t_conv_specs *specs);

int				isflag(char c);
void			specs_to_zero(t_conv_specs *specs);
void			parse_conv_specs(va_list *ap, const char **format,
		t_conv_specs *specs);
int				convert(va_list *ap, char specifier, t_conv_specs *specs);

int				ft_printf(const char *format, ...);

#endif
