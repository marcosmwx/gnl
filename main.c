/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malopes- <malopes-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:36:33 by malopes-          #+#    #+#             */
/*   Updated: 2024/10/21 10:38:03 by malopes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int	main(void)
{
	int		bytes_read;
	char	*line;
	int	fd;

	fd = 3;
	bytes_read = open("file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erro ao abrir o arquivo");
		return (1);
	}

	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	/*
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		//printf("FD: %d\n", fd);
		//printf("BUFFER_SIZE NO MAIN: %d\n", BUFFER_SIZE);
	}
	*/
	close(fd);
	return (0);
}
