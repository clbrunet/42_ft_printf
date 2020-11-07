/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:08:01 by clbrunet          #+#    #+#             */
/*   Updated: 2020/11/07 11:08:01 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		isflag(char c)
{
	int		flag_id;

	flag_id = 0;
	if (c == '#')
		flag_id = 1;
	else if (c == '0')
		flag_id = 2;
	else if (c == '-')
		flag_id = 3;
	else if (c == ' ')
		flag_id = 4;
	else if (c == '+')
		flag_id = 5;
	return (flag_id);
}

void	specs_to_zero(t_conv_specs *specs)
{
	specs->sharp = 0;
	specs->zero = 0;
	specs->minus = 0;
	specs->blank = 0;
	specs->plus = 0;
	specs->width = 0;
	specs->precision = -1;
	specs->l = 0;
	specs->h = 0;
	specs->specifier = 0;
}
