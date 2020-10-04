/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 12:13:51 by clbrunet          #+#    #+#             */
/*   Updated: 2020/10/04 12:13:51 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "debug.h"

void	print_specs(t_conv_specs *specs)
{
	printf("\n=============================\n");
	printf("# %i\n0 %i\n- %i\n' ' %i\n+ %i\n", specs->sharp, specs->zero,
			specs->minus, specs->space, specs->plus);
	printf("width %i\nprecision %i\n", specs->width, specs->precision);
	printf("=============================\n");
}
