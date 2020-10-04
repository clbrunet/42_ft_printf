/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_specs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 11:33:27 by clbrunet          #+#    #+#             */
/*   Updated: 2020/10/04 11:33:27 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "debug.h"

static int	nbrlen(long n, int len)
{
	if (n > 9)
		return (nbrlen(n / 10, len + 1));
	return (len);
}

static void putnbr_positive_long(long n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void		putnbr_specs(long n, t_conv_specs *specs)
{
	int		sign;
	int		len;
	int		width;
	int		precision;

	if (!specs->precision && !n)
	{
		while (specs->width)
		{
			ft_putchar(' ');
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
	len = nbrlen(n, (sign == 1 && !specs->plus && !specs->space) ? 1 : 2);
	width = specs->width;
	precision = specs->precision;
	if ((specs->space || specs->plus) && sign == 1
			&& (specs->width <= len || specs->minus || specs->zero))
		ft_putchar((specs->plus) ? '+' : ' ');
	if (specs->space && sign == 1 && (specs->minus || specs->zero))
		specs->width--;
	if (sign == -1)
		ft_putchar('-');
	if (specs->minus)
	{
		while (precision > len - ((sign == -1 || specs->space || specs->plus) ? 1 : 0))
		{
			ft_putchar('0');
			precision--;
		}
		putnbr_positive_long(n);
	}
	/* printf("width %i, len: %i\n", width, len); */
	while (width > specs->precision && width > len
			+ (specs->minus && (specs->space || specs->plus)) ? 1 : 0)
	{
		ft_putchar((specs->zero && !specs->minus
					&& specs->precision > specs->width) ? '0' : ' ');
		width--;
	}
	if (!specs->minus)
	{
		while (precision > len - ((sign == 1) ? 0 : 1))
		{
			ft_putchar('0');
			precision--;
		}
		putnbr_positive_long(n);
	}
}
