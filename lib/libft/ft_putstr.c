/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:17:57 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/15 12:00:10 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *string)
{
	int	i;

	i = 0;
	if (!string)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (string[i])
	{
		write(1, &string[i], 1);
		i++;
	}
	return (i);
}
