/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:27:50 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/15 12:30:23 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			str = ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == (char)c)
		str = ((char *)&s[i]);
	return ((char *)str);
}
