/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:27:52 by clbrunet          #+#    #+#             */
/*   Updated: 2020/10/09 19:27:52 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "debug.h"

int		nbrlen(unsigned long long n, int len)
{
	if (n > 9)
		return (nbrlen(n / 10, len + 1));
	return (len);
}

void	putnbr_ull_count(unsigned long long n)
{
	if (n > 9)
		putnbr_ull_count(n / 10);
	putchar_count(n % 10 + '0');
}

int		nbradd_len(int sign, t_conv_specs *specs)
{
	if (sign == -1 || specs->blank || specs->plus)
		return (1);
	return (0);
}
