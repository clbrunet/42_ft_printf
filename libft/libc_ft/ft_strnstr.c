/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:11:19 by clbrunet          #+#    #+#             */
/*   Updated: 2020/09/23 11:11:19 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*little_bp;
	int			tested_char;

	if (!big || !little)
		return (NULL);
	if (!*little)
		return ((char *)big);
	little_bp = little;
	while (*big && len)
	{
		while (len && *big && *big == *little)
		{
			big++;
			little++;
			len--;
		}
		tested_char = little - little_bp;
		if (!*little)
			return ((char *)(big - tested_char));
		big -= tested_char - 1;
		len += tested_char - 1;
		little = little_bp;
	}
	return (NULL);
}
