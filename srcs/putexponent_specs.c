/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putexponent_specs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:19:29 by clbrunet          #+#    #+#             */
/*   Updated: 2020/10/12 17:19:29 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "debug.h"

static void	putexponent_precision(long double f, int sign, int exponent, t_conv_specs *specs)
{
	unsigned long long	n;
	int					precision;

	if (!specs->zero)
	{
		if (sign == -1)
			putchar_count('-');
		else if (specs->plus)
			putchar_count('+');
		else if (specs->blank)
			putchar_count(' ');
	}
	n = (unsigned long long)f;
	f -= n;
	if (specs->precision < 0)
		precision = 6;
	else
		precision = specs->precision;
	if (specs->specifier == 'e' && round_needed(f, precision))
		n++;
	putnbr_ull_count(n);
	if (precision || specs->sharp)
		putchar_count('.');
	while (precision--)
	{
		f *= 10;
		n = (unsigned long long)f;
		f -= n;
		if (specs->specifier == 'e' && round_needed(f, precision))
			n++;
		putchar_count(n % 10 + '0');
		if (specs->specifier == 'g' && is_trailing_zero(f, precision))
			break ;
	}
	putchar_count('e');
	if (exponent < 0)
	{
		exponent *= -1;
		putchar_count('-');
	}
	else
		putchar_count('+');
	if (exponent < 10)
		putchar_count('0');
	putnbr_ull_count((unsigned long long)exponent);
}

void		putexponent_specs(long double f, int sign, t_conv_specs *specs)
{
	int		exponent_sign;
	int		exponent;
	int		len;

	exponent = 0;
	if (f <= -10 || 10 <= f)
		exponent_sign = 1;
	else
		exponent_sign = -1;
	while ((-1 < f && f < 1) || (f <= -10 || 10 < f))
	{
		if (f <= -10 || 10 <= f)
			f /= 10;
		else
			f *= 10;
		exponent++;
	}
	if (specs->minus)
		putexponent_precision(f, sign, exponent * exponent_sign, specs);
	if (specs->zero)
	{
		if (sign == -1)
			putchar_count('-');
		else if (specs->plus)
			putchar_count('+');
		else if (specs->blank)
			putchar_count(' ');
	}
	if (specs->precision > 0)
		len = nbradd_len(sign, specs) + 4 + specs->precision;
	else if (specs->precision < 0)
		len = nbradd_len(sign, specs) + 10;
	else if (specs->sharp)
		len = nbradd_len(sign, specs) + 4;
	else
		len = nbradd_len(sign, specs) + 3;
	len += nbrlen((unsigned long long)exponent, 1);
	if (exponent < 10)
		len++;
	while (specs->width > len)
	{
		if (specs->zero)
			putchar_count('0');
		else
			putchar_count(' ');
		specs->width--;
	}
	if (!specs->minus)
		putexponent_precision(f, sign, exponent * exponent_sign, specs);
}
