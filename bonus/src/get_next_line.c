/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:49:52 by fszendzi          #+#    #+#             */
/*   Updated: 2023/10/15 17:49:55 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static char	*extract_line_from_buffer(char *buffer)
{
	int		i;
	char	*line;

	if (!buffer || !buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*read_append_to_buffer(int fd, char **buffer, char **line)
{
	char	*tmp_line;
	int		bytes_read;

	tmp_line = NULL;
	bytes_read = 1;
	while (!(ft_strchr(buffer[fd], '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, *line, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(*line);
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		(*line)[bytes_read] = '\0';
		tmp_line = ft_strjoin(buffer[fd], *line);
		if (tmp_line)
		{
			free(buffer[fd]);
			buffer[fd] = tmp_line;
		}
	}
	free(*line);
	return (buffer[fd]);
}

static char	*move_pointer(char *ptr_position)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	while (ptr_position[i] && ptr_position[i] != '\n')
		i++;
	if (ptr_position[i] == '\0')
	{
		free(ptr_position);
		return (NULL);
	}
	new_buffer = malloc(sizeof(char) * (ft_strlen(ptr_position) - i++) + 1);
	if (!new_buffer)
	{
		free(ptr_position);
		return (NULL);
	}
	j = -1;
	while (ptr_position[i + (++j)])
		new_buffer[j] = ptr_position[i + j];
	new_buffer[j] = '\0';
	free(ptr_position);
	return (new_buffer);
}

static int	check_buffer_failing(char *buffer, char **line)
{
	if (!buffer)
	{
		free(*line);
		*line = NULL;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024] = {NULL};
	char		*line;

	if (fd == -1 || fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		free_buffer(buffer, fd);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	buffer[fd] = read_append_to_buffer(fd, buffer, &line);
	if (check_buffer_failing(buffer[fd], &line))
		return (NULL);
	line = extract_line_from_buffer(buffer[fd]);
	buffer[fd] = move_pointer(buffer[fd]);
	return (line);
}
