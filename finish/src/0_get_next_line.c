/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:26:38 by pratanac          #+#    #+#             */
/*   Updated: 2022/04/20 14:12:12 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_buffer(char *base, char *append)
{
	char	*join;

	join = ft_strjoin(base, append);
	free(base);
	return (join);
}

char	*set_buffer(int fd, char *buffer)
{
	int		read_file;
	char	*sub_buffer;

	read_file = 1;
	if (!buffer)
		buffer = ft_calloc(1, 1);
	sub_buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!sub_buffer)
		return (NULL);
	while (read_file > 0 && !ft_strchr(buffer, '\n'))
	{
		read_file = read(fd, sub_buffer, BUFFER_SIZE);
		if (read_file == -1)
		{
			free(sub_buffer);
			return (NULL);
		}
		sub_buffer[read_file] = 0;
		buffer = join_buffer(buffer, sub_buffer);
	}
	free(sub_buffer);
	return (buffer);
}

char	*get_line(char *buffer)
{
	int		count;
	int		i;
	char	*line;

	count = 0;
	i = 0;
	if (!buffer[count])
		return (NULL);
	while (buffer[count] && buffer[count] != '\n')
		count++;
	line = ft_calloc(sizeof(char), (count + 2));
	if (!line)
		return (NULL);
	while (i < count)
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

char	*next_buffer(char *buffer)
{
	int		count;
	int		i;
	char	*next;

	count = 0;
	while (buffer[count] && buffer[count] != '\n')
		count++;
	if (!buffer[count])
	{
		free(buffer);
		return (NULL);
	}
	next = ft_calloc((ft_strlen(buffer) - count + 1), sizeof(char));
	count++;
	i = 0;
	while (buffer[count])
		next[i++] = buffer[count++];
	free(buffer);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = set_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = next_buffer(buffer);
	return (line);
}
