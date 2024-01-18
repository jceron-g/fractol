/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:45:08 by jceron-g          #+#    #+#             */
/*   Updated: 2023/10/02 09:37:09 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	if (ft_strlen(s) == 0 || len <= 0 || start < 0 || start > ft_strlen(s))
		return ((char *)ft_calloc(1, 1));
	while (s[i] && j < len)
	{
		i++;
		j++;
	}
	substr = (char *)malloc((j + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < j)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
