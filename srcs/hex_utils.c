/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 06:31:39 by clbrunet          #+#    #+#             */
/*   Updated: 2020/11/24 06:31:39 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hexlen(unsigned long long n, int len)
{
	if (n > 15)
		return (hexlen(n / 16, len + 1));
	return (len);
}

int		hexlen_specs(unsigned long long n, int n_len, t_conv_specs *specs)
{
	int		len;

	if (specs->precision > n_len)
		len = specs->precision;
	else
		len = n_len;
	if (n && specs->sharp)
		len += 2;
	return (len);
}

int		ptrlen_specs(unsigned long long n, int n_len, t_conv_specs *specs)
{
	if (!n && !specs->precision)
		return (2);
	else if (!n && specs->precision < 0)
		return (3);
	else if (!n || specs->precision > n_len)
		return (specs->precision + 2);
	else
		return (n_len + 2);
}

void	puthex_prefix(char specifier, t_conv_specs *specs)
{
	if (specifier == 'X')
		putstr_count("0X", specs);
	else
		putstr_count("0x", specs);
}
