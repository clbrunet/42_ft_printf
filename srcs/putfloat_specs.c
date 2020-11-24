/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putfloat_specs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 06:32:01 by clbrunet          #+#    #+#             */
/*   Updated: 2020/11/24 06:32:01 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putfloat_precision(long double f, int sign, t_conv_specs *specs)
{
	unsigned long long	n;
	int					precision;

	if (!specs->zero)
		putnbr_prefix(sign, specs);
	n = (unsigned long long)f;
	f -= n;
	if (specs->precision < 0)
		precision = 6;
	else
		precision = specs->precision;
	if (round_needed(f, precision, n, specs->precision))
		n++;
	putnbr_ull_count(n, specs);
	if (precision || specs->sharp)
		putchar_count('.', specs);
	while (precision--)
	{
		f *= 10;
		n = (unsigned long long)f;
		f -= n;
		if (round_needed(f, precision, 0, -1))
			n++;
		putchar_count(n % 10 + '0', specs);
	}
}

void		putfloat_specs(long double f, int sign, t_conv_specs *specs)
{
	int		len;

	if (specs->minus)
		putfloat_precision(f, sign, specs);
	if (specs->zero)
		putnbr_prefix(sign, specs);
	len = floatlen_specs(f, sign, specs);
	while (specs->width > len)
	{
		if (specs->zero)
			putchar_count('0', specs);
		else
			putchar_count(' ', specs);
		specs->width--;
	}
	if (!specs->minus)
		putfloat_precision(f, sign, specs);
}
