/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:36:11 by clbrunet          #+#    #+#             */
/*   Updated: 2020/11/20 07:14:10 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "debug.h"

int		floatlen_specs(long double f, int sign, t_conv_specs *specs)
{
	int		int_len;

	int_len = nbrlen((unsigned long long)f, 1);
	if (specs->precision > 0)
		return (nbradd_len(sign, specs) + int_len + specs->precision + 1);
	else if (specs->precision < 0)
		return (nbradd_len(sign, specs) + int_len + 7);
	else if (specs->sharp)
		return (nbradd_len(sign, specs) + int_len + 1);
	else
		return (nbradd_len(sign, specs) + int_len);
}

int		round_needed(long double f, int left, unsigned long long nb,
		int precision)
{
	unsigned long long		n;

	f *= 10;
	n = (unsigned long long)f;
	if (precision == 0)
	{
		if (nb % 2 == 0)
			return (f > 5);
		else
			return (f >= 5);
	}
	if (!left)
		return (n >= 5);
	if (n < 9)
		return (0);
	f -= n;
	return (round_needed(f, left - 1, nb, precision));
}
