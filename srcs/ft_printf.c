/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 13:12:34 by clbrunet          #+#    #+#             */
/*   Updated: 2020/11/07 10:45:36 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "debug.h"
#include "libft.h"

void	putchar_count(char c, t_conv_specs *specs)
{
	write(1, &c, 1);
	specs->chars++;
}

void	putstr_count(char *s, t_conv_specs *specs)
{
	write(1, s, ft_strlen(s));
	specs->chars += ft_strlen(s);
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	t_conv_specs	specs;

	specs.chars = 0;
	va_start(ap, format);
	while (*format)
	{
		while (*format && *format != '%')
			putchar_count(*(format++), &specs);
		if (*format && *(++format))
		{
			parse_conv_specs(&ap, &format, &specs);
			specs.specifier = *format;
			convert(&ap, specs.specifier, &specs);
			format++;
		}
	}
	va_end(ap);
	return (specs.chars);
}
