/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 13:13:45 by clbrunet          #+#    #+#             */
/*   Updated: 2020/10/06 18:45:43 by clbrunet         ###   ########.fr       */
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
}				t_conv_specs;

void			putchar_count(char c);
void			putstr_count(char *s);

void			putchar_specs(char c, t_conv_specs *specs);
void			putstr_specs(char *s, t_conv_specs *specs);
void			putnbr_specs(long long n, t_conv_specs *specs);
void			puthex_specs(long long n, t_conv_specs *specs, char specifier);

int				parse_conv_specs(va_list *ap, const char **format,
		t_conv_specs *specs);
int				convert(va_list *ap, const char **format);

int				ft_printf(const char *format, ...);

#endif
