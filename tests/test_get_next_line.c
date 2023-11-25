/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:29:57 by anthtorr          #+#    #+#             */
/*   Updated: 2023/11/25 19:30:00 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void	show_file(char *filename)
{
	int		fd;
	short	end_file;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Problems opening <%s> file \n", filename);
		return ;
	}
	end_file = 0;
	while (!end_file)
	{
		line = get_next_line(fd);
		if (line == NULL)
			end_file = 1;
		else
			printf("%s", line);
		free(line);
	}
	close(fd);
}

int	main(void)
{
	printf(">%d<\n", BUFFER_SIZE);
	show_file("uno.txt");
	printf("--------\n");
	return (0);
}
