/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 13:12:34 by clbrunet          #+#    #+#             */
/*   Updated: 2020/09/26 13:12:34 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "debug.h"
#include "libft.h"

int		g_res = 0;

int		get_g_res(void)
{
	return (g_res);
}

void	putchar_count(char c)
{
	write(1, &c, 1);
	g_res++;
}

void	putstr_count(char *s)
{
	write(1, s, ft_strlen(s));
	g_res += ft_strlen(s);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_conv_specs specs;

	g_res = 0;
	va_start(ap, format);
	while (*format)
	{
		while (*format && *format != '%')
			putchar_count(*(format++));
		if (*format && *(++format))
		{
			parse_conv_specs(&ap, &format, &specs);
			specs.specifier = *format;
			convert(&ap, specs.specifier, &specs);
			format++;
		}
	}
	va_end(ap);
	return (g_res);
}
