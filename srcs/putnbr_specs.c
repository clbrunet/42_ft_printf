/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_specs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 06:32:06 by clbrunet          #+#    #+#             */
/*   Updated: 2020/11/24 06:32:06 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put00case(t_conv_specs *specs)
{
	if (specs->minus)
	{
		if (specs->plus)
			putchar_count('+', specs);
		else if (specs->blank)
			putchar_count(' ', specs);
	}
	if (specs->plus || specs->blank)
		specs->width--;
	while (specs->width > 0)
	{
		putchar_count(' ', specs);
		specs->width--;
	}
	if (!specs->minus)
	{
		if (specs->plus)
			putchar_count('+', specs);
		else if (specs->blank)
			putchar_count(' ', specs);
	}
}

static void	putnbr_precision(unsigned long long n, int sign, int int_len,
		t_conv_specs *specs)
{
	int		precision;

	precision = specs->precision;
	if (!(specs->zero && specs->precision < 0))
		putnbr_prefix(sign, specs);
	while (precision > int_len)
	{
		putchar_count('0', specs);
		precision--;
	}
	putnbr_ull_count(n, specs);
}

void		putnbr_specs(unsigned long long n, int sign, t_conv_specs *specs)
{
	int		int_len;
	int		len;

	if (!specs->precision && !n)
		return (put00case(specs));
	int_len = nbrlen(n, 1);
	if (specs->minus)
		putnbr_precision(n, sign, int_len, specs);
	if (specs->zero && specs->precision < 0)
		putnbr_prefix(sign, specs);
	if (specs->precision > int_len)
		len = specs->precision;
	else
		len = int_len;
	while (specs->width > len + nbradd_len(sign, specs))
	{
		if (specs->zero && specs->precision < 0)
			putchar_count('0', specs);
		else
			putchar_count(' ', specs);
		specs->width--;
	}
	if (!specs->minus)
		putnbr_precision(n, sign, int_len, specs);
}
