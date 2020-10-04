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
	int				i;
	char			c;
	char			*s;

	parse_conv_specs(ap, format, &specs);
	/* print_specs(&specs); */
	if (**format == '%')
		ft_putchar('%');
	else if (**format == 'i' || **format == 'd')
	{
		i = va_arg(*ap, int);
		putnbr_specs(i, &specs);
	}
	else if (**format == 'c')
	{
		c = (char)va_arg(*ap, int);
		ft_putchar(c);
	}
	else if (**format == 's')
	{
		s = va_arg(*ap, char *);
		ft_putstr(s);
	}
	(*format)++;
	return (1);
}
