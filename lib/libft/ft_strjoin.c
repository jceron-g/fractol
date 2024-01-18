/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:29:03 by jceron-g          #+#    #+#             */
/*   Updated: 2023/10/02 10:35:39 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	int		j;
	char	*string;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	string = (char *)malloc(((len1 + len2) * sizeof(char)) + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		string[i++] = s2[j++];
	}
	string[i] = '\0';
	return (string);
}
