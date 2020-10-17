/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putfloat_specs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 12:00:24 by clbrunet          #+#    #+#             */
/*   Updated: 2020/10/09 21:42:35 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "debug.h"

static void	putfloat_precision(long double f, int sign, t_conv_specs *specs)
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
	if (specs->specifier == 'f' && round_needed(f, precision))
		n++;
	putnbr_ull_count(n);
	if (precision || specs->sharp)
		putchar_count('.');
	while (precision--)
	{
		f *= 10;
		n = (unsigned long long)f;
		f -= n;
		if (specs->specifier == 'f' && round_needed(f, precision))
			n++;
		putchar_count(n % 10 + '0');
		if (specs->specifier == 'g' && is_trailing_zero(f, precision))
			break ;
	}
}

void		putfloat_specs(long double f, int sign, t_conv_specs *specs)
{
	int		int_len;
	int		len;

	int_len = nbrlen((unsigned long long)f, 1);
	if (specs->minus)
		putfloat_precision(f, sign, specs);
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
		len = nbradd_len(sign, specs) + int_len + specs->precision + 1;
	else if (specs->precision < 0)
		len = nbradd_len(sign, specs) + int_len + 7;
	else if (specs->sharp)
		len = nbradd_len(sign, specs) + int_len + 1;
	else
		len = nbradd_len(sign, specs) + int_len;
	while (specs->width > len)
	{
		if (specs->zero)
			putchar_count('0');
		else
			putchar_count(' ');
		specs->width--;
	}
	if (!specs->minus)
		putfloat_precision(f, sign, specs);
}
