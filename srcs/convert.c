/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 06:31:24 by clbrunet          #+#    #+#             */
/*   Updated: 2020/11/24 07:28:29 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert(va_list *ap, char specifier, t_conv_specs *specs)
{
	long long		ll;

	if (specifier == 'c')
		putchar_specs((char)va_arg(*ap, int), specs);
	else if (specifier == 's')
		putstr_specs(va_arg(*ap, char *), specs);
	else if (specifier == 'p')
		putptr_specs((unsigned long long)va_arg(*ap, void *), specs);
	else if (specifier == 'd' || specifier == 'i')
	{
		if (specs->l == 0)
			ll = (long long)va_arg(*ap, int);
		else
			ll = va_arg(*ap, long long);
		if (ll < 0)
			putnbr_specs((unsigned long long)(ll * -1), -1, specs);
		else
			putnbr_specs((unsigned long long)ll, 1, specs);
	}
	else
		convert2(ap, specifier, specs);
}

void	convert2(va_list *ap, char specifier, t_conv_specs *specs)
{
	if (specifier == 'u')
	{
		if (specs->h == 1)
			putnbr_specs((unsigned short)va_arg(*ap, unsigned), 1, specs);
		else if (specs->h == 2)
			putnbr_specs((unsigned char)va_arg(*ap, unsigned), 1, specs);
		else if (specs->l == 0)
			putnbr_specs((unsigned long long)va_arg(*ap, unsigned), 1, specs);
		else
			putnbr_specs(va_arg(*ap, unsigned long long), 1, specs);
	}
	else if (specifier == 'x' || specifier == 'X')
	{
		if (specs->h == 1)
			puthex_specs((unsigned short)va_arg(*ap, unsigned), specs);
		else if (specs->h == 2)
			puthex_specs((unsigned char)va_arg(*ap, unsigned), specs);
		else if (specs->l == 0)
			puthex_specs((unsigned long long)va_arg(*ap, unsigned), specs);
		else
			puthex_specs(va_arg(*ap, unsigned long long), specs);
	}
	else
		convert3(ap, specifier, specs);
}

void	convert3(va_list *ap, char specifier, t_conv_specs *specs)
{
	long double		ld;

	if (specifier == '%')
		putchar_specs('%', specs);
	else if (specifier == 'n')
		*(va_arg(*ap, int *)) = specs->chars;
	else if (specifier == 'f')
	{
		ld = (long double)va_arg(*ap, double);
		if (ld < 0 || (ld == -0.0 && 1 / ld == 1 / -0.0))
			putfloat_specs((long double)(ld * -1), -1, specs);
		else
			putfloat_specs((long double)ld, 1, specs);
	}
	else if (specifier == 'e')
	{
		ld = (long double)va_arg(*ap, double);
		if (ld < 0 || (ld == -0.0 && 1 / ld == 1 / -0.0))
			putexponent_specs(ld * -1, -1, specs);
		else
			putexponent_specs(ld, 1, specs);
	}
}
