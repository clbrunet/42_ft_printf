/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr_specs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 06:32:12 by clbrunet          #+#    #+#             */
/*   Updated: 2020/11/24 06:32:12 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putptr_ull(unsigned long long n, t_conv_specs *specs)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n > 15)
		putptr_ull(n / 16, specs);
	putchar_count(hex[n % 16], specs);
}

static void	putptr_precision(unsigned long long n, int len, t_conv_specs *specs)
{
	int		precision;

	if (!specs->zero || specs->precision >= 0)
		putstr_count("0x", specs);
	precision = specs->precision;
	while (precision > len)
	{
		putchar_count('0', specs);
		precision--;
	}
	if (n || specs->precision)
		putptr_ull(n, specs);
}

void		putptr_specs(unsigned long long n, t_conv_specs *specs)
{
	int		n_len;
	int		len;

	n_len = hexlen(n, 1);
	if (specs->minus)
		putptr_precision(n, n_len, specs);
	if (specs->zero && specs->precision < 0)
		putstr_count("0x", specs);
	len = ptrlen_specs(n, n_len, specs);
	while (specs->width > len)
	{
		if (specs->zero && specs->precision < 0)
			putchar_count('0', specs);
		else
			putchar_count(' ', specs);
		specs->width--;
	}
	if (!specs->minus)
		putptr_precision(n, n_len, specs);
}
