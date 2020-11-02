/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr_specs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 21:29:55 by clbrunet          #+#    #+#             */
/*   Updated: 2020/11/02 05:34:38 by runner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "debug.h"

static void	putptr_ull(unsigned long long n)
{
	char	*hex;

	hex= "0123456789abcdef";
	if (n > 15)
		putptr_ull(n / 16);
	putchar_count(hex[n % 16]);
}

static void	putptr_precision(unsigned long long n, int len, t_conv_specs *specs)
{
	int		precision;

	if (!specs->zero || specs->precision >= 0)
		putstr_count("0x");
	precision = specs->precision;
	while (precision > len)
	{
		putchar_count('0');
		precision--;
	}
	if (n || specs->precision)
		putptr_ull(n);
}

void	putptr_specs(unsigned long long n, t_conv_specs *specs)
{
	int		n_len;
	int		len;

	n_len = hexlen(n, 1);
	if (specs->minus)
		putptr_precision(n, n_len, specs);
	if (specs->zero && specs->precision < 0)
		putstr_count("0x");
	if (!n && !specs->precision)
		len = 2;
	else if (!n && specs->precision < 0)
		len = 3;
	else if (!n || specs->precision > n_len)
		len = specs->precision + 2;
	else
		len = n_len + 2;
	while (specs->width > len)
	{
		if (specs->zero && specs->precision < 0)
			putchar_count('0');
		else
			putchar_count(' ');
		specs->width--;
	}
	if (!specs->minus)
		putptr_precision(n, n_len, specs);
}
