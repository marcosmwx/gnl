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

#include "get_next_line.h"

static char *extract_line_from_buffer(char **buffer, int i) {
    char *line;
    char *remaining;

    line = ft_copy_until(*buffer, i);
    if (!line)
        return NULL;

    remaining = ft_copy_from(*buffer, i + 1);
    if (!remaining) {
        free(line);
        return NULL;
    }
    free(*buffer);
    *buffer = remaining;
    return line;
}

char *get_next_line(int fd) {
    static char *buffer = NULL;
    char temp[BUFFER_SIZE + 1];
    int bytes_read;
    int i;
    char *line = NULL;

    i = 0;
    while ((bytes_read = read(fd, temp, BUFFER_SIZE)) > 0) {
        temp[bytes_read] = '\0';
        buffer = ft_strjoin(buffer, temp);
        while (buffer[i] != '\0') {
            if (buffer[i] == '\n')
                return extract_line_from_buffer(&buffer, i);
            i++;
        }
    }
    if (bytes_read == 0 && buffer != NULL) {
        line = ft_copy_until(buffer, ft_strlen(buffer));
        free(buffer);
        return line;
    }
    free(buffer);
    return NULL;
}
