/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_specs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 06:31:48 by clbrunet          #+#    #+#             */
/*   Updated: 2020/11/24 06:31:48 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putchar_specs(char c, t_conv_specs *specs)
{
	if (specs->minus)
		putchar_count(c, specs);
	while (specs->width > 1)
	{
		if (specs->zero)
			putchar_count('0', specs);
		else
			putchar_count(' ', specs);
		specs->width--;
	}
	if (!specs->minus)
		putchar_count(c, specs);
}
