/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:35:48 by phialfai          #+#    #+#             */
/*   Updated: 2023/09/19 17:18:40 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * 
*/
size_t	ft_strlen_or_null(char *s)
{
	if (s == NULL || *s == '\0')
		return (0);
	return ((size_t) ft_strlen(s));
}

/**
 * 
*/
size_t	ft_useful_bytes_to_nl(char *buffer)
{
	size_t	bytes;

	bytes = 0;
	while (bytes < BUFFER_SIZE && buffer[bytes] != 10 && buffer[bytes] != '\0')
		bytes++;
	if (buffer[bytes] == 10)
		bytes++;
	return (bytes);
}

/**
 * 
*/
void	ft_clean_buffer(char *buffer)
{
	size_t	i;
	size_t	bytes;

	i = 0;
	bytes = ft_useful_bytes_to_nl(buffer);
	while (i < BUFFER_SIZE - bytes && buffer[i] != '\0')
	{
		buffer[i] = buffer[bytes + i];
		i++;
	}
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
}

/**
 * 
*/
char	*ft_new_line(char *line, char *buffer)
{
	size_t	ubytes;
	size_t	line_len;
	char	*new_line;

	if (line == NULL && *buffer == '\0')
		return (NULL);
	new_line = NULL;
	line_len = ft_strlen_or_null(line);
	ubytes = ft_useful_bytes_to_nl(buffer);
	if (ubytes > 0 || line_len > 0)
	{
		line_len = ft_strlen_or_null(line);
		new_line = malloc(sizeof(char) * (line_len + ubytes + 1));
		if (new_line == NULL)
			return (NULL);
		if (line != NULL)
			ft_memcpy(new_line, line, line_len);
		ft_memcpy((new_line + line_len), buffer, ubytes);
		new_line[line_len + ubytes] = '\0';
	}
	free(line);
	return (new_line);
}
