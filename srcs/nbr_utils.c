/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 06:31:43 by clbrunet          #+#    #+#             */
/*   Updated: 2020/11/24 06:31:43 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nbrlen(unsigned long long n, int len)
{
	if (n > 9)
		return (nbrlen(n / 10, len + 1));
	return (len);
}

void	putnbr_ull_count(unsigned long long n, t_conv_specs *specs)
{
	if (n > 9)
		putnbr_ull_count(n / 10, specs);
	putchar_count(n % 10 + '0', specs);
}

int		nbradd_len(int sign, t_conv_specs *specs)
{
	if (sign == -1 || specs->blank || specs->plus)
		return (1);
	return (0);
}

void	putnbr_prefix(int sign, t_conv_specs *specs)
{
	if (sign == -1)
		putchar_count('-', specs);
	else if (specs->plus)
		putchar_count('+', specs);
	else if (specs->blank)
		putchar_count(' ', specs);
}
