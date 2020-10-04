/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 09:35:00 by clbrunet          #+#    #+#             */
/*   Updated: 2020/10/04 13:04:30 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "debug.h"

static int		atoi_trim(const char **nptr)
{
	long	n;
	int		sign;

	while (**nptr == ' ')
		(*nptr)++;
	sign = 1;
	if (**nptr == '-')
	{
		sign = -1;
		(*nptr)++;
	}
	n = 0;
	while (ft_isdigit(**nptr))
	{
		n = n * 10 + **nptr - '0';
		(*nptr)++;
	}
	return (n * sign);
}

static int		isflag(char c)
{
	int		flag_id;

	flag_id = 0;
	if (c == '#')
		flag_id = 1;
	else if (c == '0')
		flag_id = 2;
	else if (c == '-')
		flag_id = 3;
	else if (c == ' ')
		flag_id = 4;
	else if (c == '+')
		flag_id = 5;
	return (flag_id);
}

static void		specs_to_zero(t_conv_specs *specs)
{
	specs->sharp = 0;
	specs->zero = 0;
	specs->minus = 0;
	specs->space = 0;
	specs->plus = 0;
	specs->width = 0;
	specs->precision = -1;
}

static void		set_flags(const char **format, t_conv_specs *specs)
{
	int		flag_id;

	specs_to_zero(specs);
	while (**format && (flag_id = isflag(**format)))
	{
		if (flag_id == 1)
			specs->sharp = 1;
		else if (flag_id == 2)
			specs->zero = 1;
		else if (flag_id == 3)
			specs->minus = 1;
		else if (flag_id == 4)
			specs->space = 1;
		else if (flag_id == 5)
			specs->plus = 1;
		(*format)++;
	}
}

int			parse_conv_specs(va_list *ap, const char **format, t_conv_specs *specs)
{
	set_flags(format, specs);
	if (**format == '*')
	{
		specs->width = va_arg(*ap, int);
		(*format)++;
	}
	else if (ft_isdigit(**format))
		specs->width = atoi_trim(format);
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			specs->precision = va_arg(*ap, int);
			(*format)++;
		}
		else if (ft_isdigit(**format))
			specs->precision = atoi_trim(format);
		else
			specs->precision = 0;
	}
	return (1);
}
