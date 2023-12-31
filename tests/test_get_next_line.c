/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:29:57 by anthtorr          #+#    #+#             */
/*   Updated: 2023/12/22 16:40:32 by anthtorr         ###   ########.fr       */
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
		if (!line)
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
/*
    show_file("1char.txt");
    printf("--------\n");

    show_file("dos.txt");
    printf("--------\n");

    show_file("empty.txt");
    printf("--------\n");
*/
	show_file("giant_line.txt");
	printf("\n--------\n");
/*
    show_file("lines_around_10.txt");
    printf("--------\n");

    show_file("multiple_nl.txt");
    printf("--------\n");

    show_file("one_line_no_nl.txt");
    printf("--------\n");

    show_file("only_nl.txt");
    printf("--------\n");

    show_file("read_error.txt");
    printf("--------\n");

    show_file("tirame");
    printf("--------\n");

    show_file("tres.txt");
    printf("--------\n");

    show_file("uno.txt");
    printf("--------\n");

    show_file("variable_nls.txt");
    printf("--------\n");

    show_file("size.txt");
    printf("--------\n");
*/
	return (0);
}
