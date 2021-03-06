/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_specs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 06:31:09 by clbrunet          #+#    #+#             */
/*   Updated: 2020/11/24 06:31:09 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putstr_precision(char *s, t_conv_specs *specs)
{
	int		precision;

	precision = specs->precision;
	while (*s && (specs->precision < 0 || precision > 0))
	{
		putchar_count(*s, specs);
		s++;
		precision--;
	}
}

void		putstr_specs(char *s, t_conv_specs *specs)
{
	int		len;

	if (!s)
		return (putstr_specs("(null)", specs));
	len = ft_strlen(s);
	if (specs->minus)
		putstr_precision(s, specs);
	if (specs->precision >= 0 && specs->precision < len)
		len = specs->precision;
	while (specs->width > len)
	{
		if (specs->zero)
			putchar_count('0', specs);
		else
			putchar_count(' ', specs);
		specs->width--;
	}
	if (!specs->minus)
		putstr_precision(s, specs);
}
