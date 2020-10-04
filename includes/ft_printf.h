/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 13:13:45 by clbrunet          #+#    #+#             */
/*   Updated: 2020/09/27 12:03:33 by clbrunet         ###   ########.fr       */
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
	int		space;
	int		plus;
	int		width;
	int		precision;
}				t_conv_specs;

void	putnbr_specs(long n, t_conv_specs *specs);
int		parse_conv_specs(va_list *ap, const char **format, t_conv_specs *specs);
int		convert(va_list *ap, const char **format);
int		ft_printf(const char *format, ...);

#endif
