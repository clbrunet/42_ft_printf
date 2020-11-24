/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 06:31:15 by clbrunet          #+#    #+#             */
/*   Updated: 2020/11/24 07:09:56 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

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
	int		chars;
}				t_conv_specs;

void			putchar_count(char c, t_conv_specs *specs);
void			putstr_count(char *s, t_conv_specs *specs);

int				hexlen(unsigned long long n, int len);
int				hexlen_specs(unsigned long long n, int n_len,
		t_conv_specs *specs);
int				ptrlen_specs(unsigned long long n, int n_len,
		t_conv_specs *specs);
void			puthex_prefix(char specifier, t_conv_specs *specs);

int				nbrlen(unsigned long long n, int len);
void			putnbr_ull_count(unsigned long long n, t_conv_specs *specs);
int				nbradd_len(int sign, t_conv_specs *specs);
void			putnbr_prefix(int sign, t_conv_specs *specs);

int				floatlen_specs(long double f, int sign, t_conv_specs *specs);
int				round_needed(long double f, int left, unsigned long long nb,
		int precision);

int				get_exponent_sign(long double f);
int				get_exponent(long double *f);
int				exponentlen_specs(int sign, int exponent, t_conv_specs *specs);
int				get_exponent_precision(t_conv_specs *specs);

void			putchar_specs(char c, t_conv_specs *specs);
void			putstr_specs(char *s, t_conv_specs *specs);
void			putptr_specs(unsigned long long n, t_conv_specs *specs);
void			putnbr_specs(unsigned long long n, int sign,
		t_conv_specs *specs);
void			puthex_specs(unsigned long long n, t_conv_specs *specs);
void			putfloat_specs(long double f, int sign, t_conv_specs *specs);
void			putexponent_specs(long double f, int sign, t_conv_specs *specs);

int				isflag(char c);
void			specs_to_zero(t_conv_specs *specs);
void			parse_conv_specs(va_list *ap, const char **format,
		t_conv_specs *specs);

void			convert(va_list *ap, char specifier, t_conv_specs *specs);
void			convert2(va_list *ap, char specifier, t_conv_specs *specs);
void			convert3(va_list *ap, char specifier, t_conv_specs *specs);

int				ft_printf(const char *format, ...);

#endif
