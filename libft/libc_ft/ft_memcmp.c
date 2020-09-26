/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:06:54 by clbrunet          #+#    #+#             */
/*   Updated: 2020/09/23 11:06:54 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*uc_s1;
	const unsigned char	*uc_s2;

	if (!s1 || !s2 || !n)
		return (0);
	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	while (*uc_s1 == *uc_s2 && --n)
	{
		uc_s1++;
		uc_s2++;
	}
	return ((int)(*uc_s1 - *uc_s2));
}
