/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_specs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 11:33:27 by clbrunet          #+#    #+#             */
/*   Updated: 2020/10/06 12:54:33 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "debug.h"

static int	nbrlen(long long n, int len)
{
	if (n > 9)
		return (nbrlen(n / 10, len + 1));
	return (len);
}

static void	putnbr_positive_ll(long long n)
{
	if (n > 9)
		putnbr_positive_ll(n / 10);
	putchar_count(n % 10 + '0');
}

static int	nbradd_len(int sign, t_conv_specs *specs)
{
	return ((sign == -1 || specs->blank || specs->plus) ? 1 : 0);
}

static void	putnbr_precision(long long n, int sign, int len,
		t_conv_specs *specs)
{
	int		precision;

	precision = specs->precision;
	if (!(specs->zero && specs->precision < 0))
	{
		if (sign == -1)
			putchar_count('-');
		else if (specs->blank || specs->plus)
			putchar_count((specs->plus) ? '+' : ' ');
	}
	while (precision > len)
	{
		putchar_count('0');
		precision--;
	}
	putnbr_positive_ll(n);
}

void		putnbr_specs(long long n, t_conv_specs *specs)
{
	int		sign;
	int		len;

	if (!specs->precision && !n)
	{
		while (specs->width)
		{
			putchar_count(' ');
			specs->width--;
		}
		return ;
	}
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	len = nbrlen(n, 1);
	if (specs->minus)
		putnbr_precision(n, sign, len, specs);
	if (specs->zero && specs->precision < 0)
	{
		if (sign == -1)
			putchar_count('-');
		else if (specs->blank || specs->plus)
			putchar_count((specs->plus) ? '+' : ' ');
	}
	while (specs->width > ((specs->precision > len) ? specs->precision : len)
			+ nbradd_len(sign, specs))
	{
		putchar_count((specs->zero && specs->precision < 0) ? '0' : ' ');
		specs->width--;
	}
	if (!specs->minus)
		putnbr_precision(n, sign, len, specs);
}
