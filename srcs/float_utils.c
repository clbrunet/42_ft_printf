/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:36:11 by clbrunet          #+#    #+#             */
/*   Updated: 2020/10/13 13:36:11 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "debug.h"

int		round_needed(long double f, int left, int precision)
{
	unsigned long long		n;

	f *= 10;
	n = (unsigned long long)f;
	/* printf("%Lf, %llu, %i", f, n, precision); */
	if (precision == 0)
		return (n >= 5);
	if (!left)
		return (n >= 5);
	if (n < 9)
		return (0);
	f -= n;
	return (round_needed(f, left - 1, precision));
}

int		is_trailing_zero(long double f, int left)
{
	unsigned long long		n;

	f *= 10;
	n = (unsigned long long)f;
	if (!left)
		return (n == 0);
	if (n != 0)
		return (0);
	f -= n;
	return (is_trailing_zero(f, left - 1));
}
