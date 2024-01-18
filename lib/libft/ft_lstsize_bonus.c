/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:01:02 by jceron-g          #+#    #+#             */
/*   Updated: 2023/09/28 11:59:36 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*aux_node;

	if (!lst)
		return (0);
	size = 1;
	aux_node = lst;
	while (aux_node->next)
	{
		aux_node = aux_node->next;
		size++;
	}
	return (size);
}
