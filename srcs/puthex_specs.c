/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_specs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 06:31:58 by clbrunet          #+#    #+#             */
/*   Updated: 2020/11/24 06:31:58 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	puthex_null(t_conv_specs *specs)
{
	while (specs->width)
	{
		putchar_count(' ', specs);
		specs->width--;
	}
}

static void	puthex_ull(unsigned long long n, char specifier,
		t_conv_specs *specs)
{
	char	*hex_lowercase;
	char	*hex_uppercase;

	hex_lowercase = "0123456789abcdef";
	hex_uppercase = "0123456789ABCDEF";
	if (n > 15)
		puthex_ull(n / 16, specifier, specs);
	if (specifier == 'X')
		putchar_count(hex_uppercase[n % 16], specs);
	else
		putchar_count(hex_lowercase[n % 16], specs);
}

static void	puthex_precision(unsigned long long n, int len, t_conv_specs *specs)
{
	int		precision;

	if ((!specs->zero || specs->precision >= 0) && specs->sharp && n)
		puthex_prefix(specs->specifier, specs);
	precision = specs->precision;
	while (precision > len)
	{
		putchar_count('0', specs);
		precision--;
	}
	puthex_ull(n, specs->specifier, specs);
}

void		puthex_specs(unsigned long long n, t_conv_specs *specs)
{
	int		len;
	int		n_len;

	if (!specs->precision && !n)
		return (puthex_null(specs));
	n_len = hexlen(n, 1);
	if (specs->minus)
		puthex_precision(n, n_len, specs);
	if (specs->zero && specs->precision < 0 && specs->sharp && n)
		puthex_prefix(specs->specifier, specs);
	len = hexlen_specs(n, n_len, specs);
	while (specs->width > len)
	{
		if (specs->zero && specs->precision < 0)
			putchar_count('0', specs);
		else
			putchar_count(' ', specs);
		specs->width--;
	}
	if (!specs->minus)
		puthex_precision(n, n_len, specs);
}
