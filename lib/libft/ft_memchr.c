/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:57:51 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/15 12:26:06 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*string;
	char	target;
	size_t	i;

	string = ((char *)s);
	target = ((char)c);
	i = 0;
	while (i < n)
	{
		if (string[i] != target)
			i++;
		else
			return ((char *)&s[i]);
	}
	return (0);
}
