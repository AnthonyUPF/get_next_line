/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:26:41 by anthtorr          #+#    #+#             */
/*   Updated: 2023/11/25 19:50:04 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_buff(int fd, char	*read_buf, ssize_t *read_bytes)
{
	char		*read_raw;
	char		*new_buf;

	read_raw = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read_raw == NULL)
		return (my_free(&read_buf));
	*read_bytes = read(fd, read_raw, BUFFER_SIZE);
	if (*read_bytes <= 0)
	{
		my_free(&read_raw);
		if (*read_bytes == -1)
			return (my_free(&read_buf));
		return (read_buf);
	}
	read_raw[*read_bytes] = '\0';
	new_buf = gnl_join(read_buf, read_raw);
	my_free(&read_raw);
	if (new_buf == NULL)
		return (NULL);
	my_free(&read_buf);
	return (new_buf);
}

char	*buff_analisis(char	**read_buf)
{
	char	*line;
	char	*new_buf;
	ssize_t	buf_len;
	ssize_t	ret;

	if (*read_buf == NULL)
		return (NULL);
	buf_len = gnl_strlen_and_nl(&ret, read_buf[0]);
	if (ret == -1)
		return (NULL);
	line = gnl_substr(*read_buf, 0, (ret + 1));
	if (!line)
		return (NULL);
	new_buf = gnl_substr(*read_buf, (ret + 1), (buf_len - (ret + 1)));
	if (!new_buf && (buf_len - (ret + 1)))
		return (my_free(&line));
	free(*read_buf);
	*read_buf = new_buf;
	return (line);
}

char	*buff_flush(char **read_buf)
{
	char	*line;
	size_t	i;

	if (*read_buf == NULL)
		return (my_free(read_buf));
	i = gnl_strlen(read_buf[0]);
	line = (char *)malloc(i + 1);
	if (!line)
		return (my_free(read_buf));
	i = 0;
	while (read_buf[0][i] != '\0')
	{
		line[i] = read_buf[0][i];
		i++;
	}
	line[i] = '\0';
	my_free(read_buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*read_buf;
	ssize_t		read_bytes;
	char		*line;

	while ((0 <= fd && fd <= FOPEN_MAX) && (BUFFER_SIZE > 0))
	{
		line = buff_analisis(&read_buf);
		if (line)
			return (line);
		read_buf = read_to_buff(fd, read_buf, &read_bytes);
		if (!read_buf && (read_bytes == -1))
		{
			free(line);
			return (my_free(&read_buf));
		}
		if (!read_buf && (read_bytes == 0))
			return (my_free(&read_buf));
		if (read_buf && (read_bytes == 0))
			return (buff_flush(&read_buf));
	}
	return (NULL);
}
