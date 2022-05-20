/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:24:59 by aquincho          #+#    #+#             */
/*   Updated: 2022/05/19 10:25:34 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cutline(char *buffer)
{
	char	*line;

	line = buffer;
	return (line);
}

char	*ft_read(int fd, char *buffer)
{
	char	*tmp;
	char	*buf_read;
	int		bytes_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	buf_read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buf_read, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf_read);
			return (NULL);
		}
		buf_read[bytes_read] = '\0';
		tmp = ft_strjoin(buffer, buf_read);
		if (!tmp)
			return (NULL);
		free(buffer);
		buffer = tmp;
	}
	free(buf_read);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_cutline(buffer);
	return (line);
}
