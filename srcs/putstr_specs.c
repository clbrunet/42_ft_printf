/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_specs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:34:45 by clbrunet          #+#    #+#             */
/*   Updated: 2020/10/07 14:34:45 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "debug.h"

static void	putstr_precision(char *s, t_conv_specs *specs)
{
	int		precision;

	precision = specs->precision;
	while (*s && (specs->precision < 0 || precision > 0))
	{
		putchar_count(*s);
		s++;
		precision--;
	}
}

void		putstr_specs(char *s, t_conv_specs *specs)
{
	int		len;

	if (!s)
	{
		specs->precision = -1;
		putstr_specs("(null)", specs);
		return ;
	}
	len = ft_strlen(s);
	if (specs->minus)
		putstr_precision(s, specs);
	while (specs->width > ((specs->precision >= 0 && specs->precision < len)
				? specs->precision : len))
	{
		putchar_count(' ');
		specs->width--;
	}
	if (!specs->minus)
		putstr_precision(s, specs);
}
