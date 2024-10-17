/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malopes- <malopes-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:37:45 by malopes-          #+#    #+#             */
/*   Updated: 2024/10/17 19:40:17 by malopes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

char *mall(char *buf, int chars_read)
{
	int	c;
	char	*new;
	c = 0;
	new = (char *)malloc(chars_read * sizeof(char));
	if (!new)
		return (NULL);
	while (buf[c] != '\0')
	{
		new[c] = buf[c];
		c++;
	}
	return (new);
}

int main()
{
	int	fd;
	char	buf[256];
	char	*re;
	int	chars_read;

	fd = open("file.txt", O_RDONLY);

	while ((chars_read = read(fd, buf, 5)))
	{
		if (*buf)
		{
			buf[chars_read] = '\0';
			re = mall(buf, chars_read);
		}
		printf("%s", re);
		free(re);
	//	printf("%s", buf);
	}
	return (0);	
}
