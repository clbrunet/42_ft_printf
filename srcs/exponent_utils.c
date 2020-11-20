/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exponent_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 10:26:54 by clbrunet          #+#    #+#             */
/*   Updated: 2020/11/20 10:26:54 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_exponent_sign(long double f)
{
	if (f <= -10 || 10 <= f || f == 0)
		return (1);
	else
		return (-1);
}

int		get_exponent(long double *f)
{
	int		exponent;

	exponent = 0;
	while (*f != 0 && ((-1 < *f && *f < 1) || (*f <= -10 || 10 < *f)))
	{
		if (*f <= -10 || 10 <= *f)
			*f /= 10;
		else
			*f *= 10;
		exponent++;
	}
	return (exponent);
}

int		exponentlen_specs(int sign, int exponent, t_conv_specs *specs)
{
	int		len;

	if (specs->precision > 0)
		len = 4 + specs->precision;
	else if (specs->precision < 0)
		len = 10;
	else if (specs->sharp)
		len = 4;
	else
		len = 3;
	len += nbradd_len(sign, specs) + nbrlen((unsigned long long)exponent, 1);
	if (exponent < 10)
		len++;
	return (len);
}

int		get_exponent_precision(t_conv_specs *specs)
{
	if (specs->precision < 0)
		return (6);
	else
		return (specs->precision);
}
