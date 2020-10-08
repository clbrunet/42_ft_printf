/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_specs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:35:57 by clbrunet          #+#    #+#             */
/*   Updated: 2020/10/07 20:35:57 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "debug.h"

static int	addlen(long long n, t_conv_specs *specs, char specifier)
{
	if (n && (specifier == 'p' || specs->sharp))
		return (2);
	return (0);
}

static int	hexlen(long long n, int len)
{
	if (n > 15)
		return (hexlen(n / 16, len + 1));
	return (len);
}

static void	puthex_positive_ll(long long n, char specifier)
{
	char	*hex_lowercase;
	char	*hex_uppercase;

	hex_lowercase = "0123456789abcdef";
	hex_uppercase = "0123456789ABCDEF";
	if (n > 15)
		puthex_positive_ll(n / 16, specifier);
	putchar_count((specifier == 'X') ? hex_uppercase[n % 16] : hex_lowercase[n % 16]);
}

static void	puthex_precision(long long n, int len,
		t_conv_specs *specs, char specifier)
{
	int		precision;

	if (n && (specifier == 'p' || specs->sharp))
		putstr_count((specifier == 'X') ?  "0X" :"0x");
	precision = specs->precision;
	while (precision > len)
	{
		putchar_count('0');
		precision--;
	}
	puthex_positive_ll(n, specifier);
}

void	puthex_specs(long long n, t_conv_specs *specs, char specifier)
{
	int		len;

	if (specifier == 'p' && !n)
	{
		putstr_specs("(nil)", specs);
		return ;
	}
	if (!specs->precision && !n)
	{
		while (specs->width)
		{
			putchar_count(' ');
			specs->width--;
		}
		return ;
	}
	len = hexlen(n, 1);
	if (specs->minus)
		puthex_precision(n, len, specs, specifier);
	while (specs->width > ((specs->precision > len) ? specs->precision : len)
			+ addlen(n, specs, specifier))
	{
		putchar_count((specs->zero && specs->precision < 0) ? '0' : ' ');
		specs->width--;
	}
	if (!specs->minus)
		puthex_precision(n, len, specs, specifier);
}
