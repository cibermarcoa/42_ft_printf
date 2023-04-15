/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiaz-ca <mdiaz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:02:13 by mdiaz-ca          #+#    #+#             */
/*   Updated: 2023/03/23 22:23:54 by mdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux_lst;
	t_list	*aux_node;

	aux_lst = NULL;
	while (lst)
	{
		aux_node = ft_lstnew(f(lst->content));
		if (!aux_node)
		{
			ft_lstclear(&aux_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&aux_lst, aux_node);
		lst = lst->next;
	}
	return (aux_lst);
}
