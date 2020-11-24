/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 06:32:26 by clbrunet          #+#    #+#             */
/*   Updated: 2020/11/24 07:29:18 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	atoi_trim(const char **nptr)
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

static void	set_flags(const char **format, t_conv_specs *specs)
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
			specs->blank = 1;
		else if (flag_id == 5)
			specs->plus = 1;
		(*format)++;
	}
}

static void	parse_precision(va_list *ap, const char **format,
		t_conv_specs *specs)
{
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
}

static void	parse_size(const char **format, t_conv_specs *specs)
{
	while (**format == 'l')
	{
		specs->l++;
		(*format)++;
	}
	while (**format == 'h')
	{
		specs->h++;
		(*format)++;
	}
}

void		parse_conv_specs(va_list *ap, const char **format,
		t_conv_specs *specs)
{
	set_flags(format, specs);
	if (**format == '*')
	{
		specs->width = va_arg(*ap, int);
		if (specs->width < 0)
		{
			specs->minus = 1;
			specs->width *= -1;
		}
		(*format)++;
	}
	else if (ft_isdigit(**format))
		specs->width = atoi_trim(format);
	parse_precision(ap, format, specs);
	parse_size(format, specs);
	if (specs->minus)
		specs->zero = 0;
	if (specs->plus)
		specs->blank = 0;
}
