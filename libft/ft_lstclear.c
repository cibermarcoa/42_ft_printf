/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiaz-ca <mdiaz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:02:13 by mdiaz-ca          #+#    #+#             */
/*   Updated: 2023/03/15 19:02:54 by mdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux_lst;

	aux_lst = *lst;
	while (aux_lst)
	{
		aux_lst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = aux_lst;
	}
}
