/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:08:23 by jceron-g          #+#    #+#             */
/*   Updated: 2023/09/29 10:33:35 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux_lst;

	aux_lst = *lst;
	while (*lst)
	{
		aux_lst = aux_lst->next;
		ft_lstdelone(*lst, del);
		*lst = aux_lst;
	}
}
