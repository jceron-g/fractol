/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:46:07 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/15 12:30:12 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	char		*str1;
	char		*str2;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	while (i < n && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] == str2[i])
		{
			i++;
		}
		else
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
	}
	return (0);
}
