/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:10:42 by clbrunet          #+#    #+#             */
/*   Updated: 2020/09/23 11:10:42 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*u_s1;
	const unsigned char	*u_s2;

	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	if (!u_s1 || !u_s2 || !n)
		return (0);
	while (*u_s1 && *u_s1 == *u_s2 && --n)
	{
		u_s1++;
		u_s2++;
	}
	return ((int)(*u_s1 - *u_s2));
}
