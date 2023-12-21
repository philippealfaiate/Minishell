/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phialfai <phialfai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 00:55:17 by phialfai          #+#    #+#             */
/*   Updated: 2023/09/19 17:08:34 by phialfai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * 
*/
char	*ft_get_line(int fd, char *line)
{
	char			*new_line;
	int				readed_bytes;
	static char		buffer[BUFFER_SIZE];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 0)
		return (NULL);
	if (*buffer == 0)
	{
		readed_bytes = read(fd, buffer, BUFFER_SIZE);
		if (readed_bytes == -1)
			return (free(line), NULL);
		if (readed_bytes == 0)
			return (line);
	}
	new_line = ft_new_line(line, buffer);
	ft_clean_buffer(buffer);
	if (new_line[ft_strlen(new_line) - 1] == '\n')
		return (new_line);
	return (ft_get_line(fd, new_line));
}

/**
 * 
*/
char	*get_next_line(int fd)
{
	return (ft_get_line(fd, NULL));
}
