/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:19:51 by jceron-g          #+#    #+#             */
/*   Updated: 2024/01/15 11:33:14 by jceron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_line(int fd, char *aux_line)
{
	char	*buffer;
	char	*save_aux;
	int		read_bytes;

	buffer = ft_calloc_gnl((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr_gnl(buffer, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(aux_line);
			aux_line = NULL;
			return (NULL);
		}
		save_aux = aux_line;
		aux_line = ft_strjoin_gnl(save_aux, buffer, read_bytes);
	}
	free(buffer);
	if (ft_strlen_gnl(aux_line) == 0)
		return (free(aux_line), NULL);
	return (aux_line);
}

char	*ft_get_line(char *aux_line)
{
	int		i;
	int		j;
	char	*get_line;

	i = 0;
	while (aux_line[i] != '\0' && aux_line[i] != '\n')
		i++;
	get_line = ft_calloc_gnl((i + 1 + (aux_line[i] == '\n')), sizeof(char));
	if (!get_line)
		return (NULL);
	j = 0;
	while (aux_line[j] != '\0' && aux_line[j] != '\n')
	{
		get_line[j] = aux_line[j];
		j++;
	}
	if (aux_line[j] == '\n')
		get_line[j++] = '\n';
	get_line[j] = '\0';
	return (get_line);
}

char	*ft_clean_line(char *aux_line)
{
	int		i;
	int		j;
	char	*new_aux_line;

	i = 0;
	while (aux_line[i] != '\0' && aux_line[i] != '\n')
		i++;
	if (ft_strlen_gnl(aux_line) - i <= 0)
	{
		free(aux_line);
		aux_line = NULL;
		return (NULL);
	}
	new_aux_line = ft_calloc_gnl(ft_strlen_gnl(aux_line) - i + 1, sizeof(char));
	if (!new_aux_line)
		return (NULL);
	i++;
	j = 0;
	while (aux_line[i] != '\0')
		new_aux_line[j++] = aux_line[i++];
	free(aux_line);
	aux_line = NULL;
	return (new_aux_line);
}

char	*get_next_line(int fd)
{
	static char	*aux_line;
	char		*final_line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free(aux_line);
		aux_line = NULL;
		return (NULL);
	}
	aux_line = ft_read_line(fd, aux_line);
	if (!aux_line)
		return (NULL);
	final_line = ft_get_line(aux_line);
	aux_line = ft_clean_line(aux_line);
	return (final_line);
}
