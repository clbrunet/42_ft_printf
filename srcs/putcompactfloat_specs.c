/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putcompactfloat_specs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 11:35:09 by clbrunet          #+#    #+#             */
/*   Updated: 2020/10/13 11:35:09 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "debug.h"

void		putcompactfloat_specs(long double f, int sign, t_conv_specs *specs)
{
	long double	f_bp;
	int			exponent_sign;
	int			exponent;
	int			precision;

	f_bp = f;
	exponent = 0;
	if (f <= -10 || 10 <= f)
		exponent_sign = 1;
	else
		exponent_sign = -1;
	while ((-1 < f && f < 1) || (f <= -10 || 10 <= f))
	{
		if (f <= -10 || 10 <= f)
			f /= 10;
		else
			f *= 10;
		exponent++;
	}
	if (specs->precision < 0)
		precision = 6;
	else if (specs->precision == 0)
	{
		specs->precision = 1;
		precision = 1;
	}
	else
		precision = specs->precision;
	if ((exponent_sign == -1 && exponent > 4) || (exponent_sign == 1
				&& exponent >= precision))
		putexponent_specs(f_bp, sign, specs);
	else
		putfloat_specs(f_bp, sign, specs);
}
