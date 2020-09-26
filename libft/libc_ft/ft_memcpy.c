/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:02:00 by clbrunet          #+#    #+#             */
/*   Updated: 2020/09/23 11:02:00 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*s_dest;
	const char	*s_src;

	if (!dest || !src)
		return (dest);
	s_dest = (char *)dest;
	s_src = (char *)src;
	while (n--)
		*(s_dest++) = *(s_src++);
	return (dest);
}
