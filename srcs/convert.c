/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 09:34:07 by clbrunet          #+#    #+#             */
/*   Updated: 2020/09/27 09:34:07 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "debug.h"

int		convert(va_list *ap, const char **format)
{
	t_conv_specs	specs;
	long long		n;
	char			c;
	char			*s;

	parse_conv_specs(ap, format, &specs);
	if (**format == 'c')
	{
		c = (char)va_arg(*ap, int);
		putchar_specs(c, &specs);
	}
	else if (**format == 's')
	{
		s = va_arg(*ap, char *);
		putstr_specs(s, &specs);
	}
	else if (**format == 'p')
	{
		n = (long long)va_arg(*ap, char *);
		puthex_specs(n, &specs, 'p');
	}
	else if (**format == 'd' || **format == 'i')
	{
		n = (long long)va_arg(*ap, int);
		putnbr_specs(n, &specs);
	}
	else if (**format == 'u')
	{
		n = (long long)va_arg(*ap, unsigned);
		putnbr_specs(n, &specs);
	}
	else if (**format == 'x')
	{
		n = (long long)va_arg(*ap, unsigned);
		puthex_specs(n, &specs, 'x');
	}
	else if (**format == 'X')
	{
		n = (long long)va_arg(*ap, unsigned);
		puthex_specs(n, &specs, 'X');
	}
	else if (**format == '%')
		putchar_specs('%', &specs);
	(*format)++;
	return (1);
}
