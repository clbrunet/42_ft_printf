/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 09:34:07 by clbrunet          #+#    #+#             */
/*   Updated: 2020/10/13 13:20:59 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "debug.h"
#include <stdarg.h>

int		convert(va_list *ap, char specifier, t_conv_specs *specs)
{
	long long		ll;
	long double		ld;

	if (specifier == 'c')
		putchar_specs((char)va_arg(*ap, int), specs);
	else if (specifier == 's')
		putstr_specs(va_arg(*ap, char *), specs);
	else if (specifier == 'p')
		puthex_specs((unsigned long long)va_arg(*ap, void *), specs);
	else if (specifier == 'd' || specifier == 'i')
	{
		if (specs->l == 0)
			ll = (long long)va_arg(*ap, int);
		/* else if (specs.l == 1) */
		/* 	ll = (long long)va_arg(*ap, long); */
		else
			ll = va_arg(*ap, long long);
		if (ll < 0)
			putnbr_specs((unsigned long long)(ll * -1), -1, specs);
		else
			putnbr_specs((unsigned long long)ll, 1, specs);
	}
	else if (specifier == 'u')
		putnbr_specs(va_arg(*ap, unsigned long long), 1, specs);
	else if (specifier == 'x')
		puthex_specs(va_arg(*ap, unsigned long long), specs);
	else if (specifier == 'X')
		puthex_specs(va_arg(*ap, unsigned long long), specs);
	else if (specifier == '%')
		putchar_specs('%', specs);
	else if (specifier == 'n')
		*(va_arg(*ap, int *)) = get_g_res();
	else if (specifier == 'f')
	{
		if (specs->l == 0)
			ld = (long double)va_arg(*ap, double);
		else
			ld = va_arg(*ap, long double);
		if (ld < 0)
			putfloat_specs((long double)(ld * -1), -1, specs);
		else
			putfloat_specs((long double)ld, 1, specs);
	}
	else if (specifier == 'g')
	{
		if (specs->l == 0)
			ld = (long double)va_arg(*ap, double);
		else
			ld = va_arg(*ap, long double);
		if (ld < 0)
			putcompactfloat_specs((long double)(ld * -1), -1, specs);
		else
			putcompactfloat_specs((long double)ld, 1, specs);
	}
	else if (specifier == 'e')
	{
		if (specs->l == 0)
			ld = (long double)va_arg(*ap, double);
		else
			ld = va_arg(*ap, long double);
		if (ld < 0)
			putexponent_specs(ld * -1, -1, specs);
		else
			putexponent_specs(ld, 1, specs);
	}
	return (1);
}
