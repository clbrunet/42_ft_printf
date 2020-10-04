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

int		ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{
		while (*format && *format != '%')
			ft_putchar(*(format++));
		if (*format && *(++format))
		{
			convert(&ap, &format);
		}
	}
	va_end(ap);
	return (0);
}