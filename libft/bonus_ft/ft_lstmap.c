/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 06:06:04 by clbrunet          #+#    #+#             */
/*   Updated: 2020/09/25 06:06:04 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;

	if (!lst)
		return ((t_list *)NULL);
	(void)del;
	if (!(map = ft_lstnew((*f)(lst->content))))
		return ((t_list *)NULL);
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&map, ft_lstnew((*f)(lst->content)));
		lst = lst->next;
	}
	return (map);
}
