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

static void	putnbr_precision(unsigned long long n, int sign, int int_len,
		t_conv_specs *specs)
{
	int		precision;

	precision = specs->precision;
	if (!(specs->zero && specs->precision < 0))
	{
		if (sign == -1)
			putchar_count('-');
		else if (specs->plus)
			putchar_count('+');
		else if (specs->blank)
			putchar_count(' ');
	}
	while (precision > int_len)
	{
		putchar_count('0');
		precision--;
	}
	putnbr_ull_count(n);
}

void		putnbr_specs(unsigned long long n, int sign, t_conv_specs *specs)
{
	int		int_len;
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
	int_len = nbrlen(n, 1);
	if (specs->minus)
		putnbr_precision(n, sign, int_len, specs);
	if (specs->zero && specs->precision < 0)
	{
		if (sign == -1)
			putchar_count('-');
		else if (specs->plus)
			putchar_count('+');
		else if (specs->blank)
			putchar_count(' ');
	}
	if (specs->precision > int_len)
		len = specs->precision;
	else
		len = int_len;
	while (specs->width > len + nbradd_len(sign, specs))
	{
		if (specs->zero && specs->precision < 0)
			putchar_count('0');
		else
			putchar_count(' ');
		specs->width--;
	}
	if (!specs->minus)
		putnbr_precision(n, sign, int_len, specs);
}
