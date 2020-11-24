/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putexponent_specs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 06:31:53 by clbrunet          #+#    #+#             */
/*   Updated: 2020/11/24 06:31:53 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putexponent_suffix(int exponent, t_conv_specs *specs)
{
	putchar_count('e', specs);
	if (exponent < 0)
	{
		exponent *= -1;
		putchar_count('-', specs);
	}
	else
		putchar_count('+', specs);
	if (exponent < 10)
		putchar_count('0', specs);
	putnbr_ull_count((unsigned long long)exponent, specs);
}

static void	putexponent_int(long double *f, int *exponent, int precision,
		t_conv_specs *specs)
{
	unsigned long long	n;

	n = (unsigned long long)*f;
	*f -= n;
	if (round_needed(*f, precision, n, specs->precision))
		n++;
	if (n == 10)
	{
		n = 1;
		(*exponent)++;
	}
	putnbr_ull_count(n, specs);
}

static void	putexponent_precision(long double f, int sign, int exponent,
		t_conv_specs *specs)
{
	unsigned long long	n;
	int					precision;

	if (!specs->zero)
		putnbr_prefix(sign, specs);
	precision = get_exponent_precision(specs);
	putexponent_int(&f, &exponent, precision, specs);
	if (precision || specs->sharp)
		putchar_count('.', specs);
	while (precision--)
	{
		f *= 10;
		n = (unsigned long long)f;
		f -= n;
		if (round_needed(f, precision, -1, specs->precision))
			n++;
		putchar_count(n % 10 + '0', specs);
	}
	putexponent_suffix(exponent, specs);
}

void		putexponent_specs(long double f, int sign, t_conv_specs *specs)
{
	int			exponent_sign;
	int			exponent;
	int			len;

	exponent_sign = get_exponent_sign(f);
	exponent = get_exponent(&f);
	if (specs->minus)
		putexponent_precision(f, sign, exponent * exponent_sign, specs);
	if (specs->zero)
		putnbr_prefix(sign, specs);
	len = exponentlen_specs(sign, exponent, specs);
	while (specs->width > len)
	{
		if (specs->zero)
			putchar_count('0', specs);
		else
			putchar_count(' ', specs);
		specs->width--;
	}
	if (!specs->minus)
		putexponent_precision(f, sign, exponent * exponent_sign, specs);
}
