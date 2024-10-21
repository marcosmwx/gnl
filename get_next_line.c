/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malopes- <malopes-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:37:45 by malopes-          #+#    #+#             */
/*   Updated: 2024/10/18 15:07:43 by malopes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
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
        buffer = NULL;
        return line;
    }
    free(buffer);
    return NULL;
}

*/

char *ft_strchr(const char *s, int c) {
    if (!s) 
        return NULL;
    while (*s) {
        if (*s == (char)c) {
            return (char *)s;
        }
        s++;
    }
    return NULL;
}

int ft_strlen(const char *s) {
    int i;

    if (!s) 
        return (0);
    i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

char *ft_strdup(const char *src) {
    int i;

    i = 0;
    if (!src)
        return NULL;
    int len = ft_strlen(src);
    char *dup = (char *)malloc(sizeof(char) * (len + 1));
    if (!dup) return NULL;
    while (src[++i] != '\0')
        dup[i] = src[i];
    dup[len] = '\0';
    return dup;
}

char *ft_strjoin(char *s1, char *s2) {
    int len1;
    int len2;
    char *result;
    int i;

    if (!s2) 
        return s1;
    if (!s1)
        s1 = ft_strdup("");
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    result = (char *)malloc(sizeof(char) * ((len1 + len2) + 1));
    if (!result)
        return NULL;
    i = -1;
    while (++i < len1)
        result[i] = s1[i];

    i = -1;
    while (++i < len2)
        result[len1 + i] = s2[i];
    result[len1 + len2] = '\0';
    free(s1);
    return result;
}

char *ft_copy_until(char *src, int n) {
    char *dest;
    int i;

    dest = (char *)malloc(sizeof(char) *(n + 2)); // n + 1 para o '\n' e +1 para o '\0'
    if (!dest)
        return NULL;
    i = 0;
    while (i <= n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *ft_copy_from(char *src, int n) {
    if (src == NULL || src[n] == '\0')
        return NULL;
    char *dest = (char *)malloc(sizeof(char) * (ft_strlen(src + n) + 1));
    if (!dest)
         return NULL;
    int i = 0;
    while (src[n + i] != '\0') {
        dest[i] = src[n + i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

static char *extract_line_from_buffer(char **buffer, int i) {
    char *line;
    
    line = ft_copy_until(*buffer, i);
    if (!line)
        return NULL;
    char *remaining = ft_copy_from(*buffer, i + 1);
    free(*buffer);
    *buffer = remaining;
    return line;
}

char *get_next_line(int fd) {
    static char *buffer = NULL;
    char temp[BUFFER_SIZE + 1];
    int bytes_read;
    int i;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    while ((bytes_read = read(fd, temp, BUFFER_SIZE)) > 0) {
        temp[bytes_read] = '\0';
        buffer = ft_strjoin(buffer, temp);
        if (!buffer)
            return NULL;

        // Verifica se o buffer contém um '\n'
        if (ft_strchr(buffer, '\n')) {
            i = 0;
            while (buffer[i] != '\0') {
                if (buffer[i] == '\n') {
                    return extract_line_from_buffer(&buffer, i);
                }
                i++;
            }
        }
    }

    // Verificação final: se o arquivo acabou e o buffer contém '\n'
    if (bytes_read == 0 && buffer != NULL) {
        if (ft_strchr(buffer, '\n')) {
            i = 0;
            while (buffer[i] != '\0') {
                if (buffer[i] == '\n') {
                    return extract_line_from_buffer(&buffer, i);
                }
                i++;
            }
        }
        // Se chegamos ao fim e o buffer tem conteúdo restante (sem '\n')
        if (*buffer != '\0') {
            char *line = ft_copy_until(buffer, ft_strlen(buffer) - 1);
            free(buffer);
            buffer = NULL;
            return line;
        }
    }

    // Limpeza do buffer se nada mais restar
    free(buffer);
    buffer = NULL;
    return NULL;
}
