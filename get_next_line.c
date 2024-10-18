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
    while (*s) {
        if (*s == (char)c) {
            return (char *)s;
        }
        s++;
    }
    return NULL;
}

int ft_strlen(const char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

char *ft_strdup(const char *src) {
    int len = ft_strlen(src);
    char *dup = (char *)malloc(sizeof(char) * (len + 1));
    if (!dup) return NULL;
    for (int i = 0; i < len; i++)
        dup[i] = src[i];
    dup[len] = '\0';
    return dup;
}

char *ft_strjoin(char *s1, char *s2) {
    int len1 = ft_strlen(s1 ? s1 : "");
    int len2 = ft_strlen(s2);
    char *result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
    if (!result) return NULL;
    int i = 0;
    if (s1) {
        while (i < len1) {
            result[i] = s1[i];
            i++;
        }
        free(s1); // Libera o buffer antigo
    }
    for (int j = 0; j < len2; j++) {
        result[i++] = s2[j];
    }
    result[i] = '\0';
    return result;
}

char *ft_copy_until(char *src, int n) {
    if (src == NULL || n < 0 || src[n] == '\0') {
        return NULL; // Retorna NULL se n é inválido
    }
    char *dest = (char *)malloc(sizeof(char) * (n + 2)); // n + 1 para o '\n' e +1 para o '\0'
    if (!dest) return NULL;
    for (int i = 0; i <= n; i++) {
        dest[i] = src[i];
    }
    dest[n + 1] = '\0'; // Termina a string
    return dest;
}

char *ft_copy_from(char *src, int n) {
    if (src == NULL || src[n] == '\0') {
        return NULL; // Retorna NULL se n é o final da string
    }
    char *dest = (char *)malloc(sizeof(char) * (ft_strlen(src + n) + 1));
    if (!dest) return NULL;
    int i = 0;
    while (src[n + i] != '\0') {
        dest[i] = src[n + i];
        i++;
    }
    dest[i] = '\0'; // Termina a string
    return dest;
}

static char *extract_line_from_buffer(char **buffer, int i) {
    char *line = ft_copy_until(*buffer, i);
    if (!line) return NULL;

    char *remaining = ft_copy_from(*buffer, i + 1);
    free(*buffer);
    *buffer = remaining; // Atualiza o buffer
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
        if (!buffer) return NULL; // Verifica se a junção foi bem-sucedida

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

    if (bytes_read == 0 && buffer != NULL) {
        // Retorna a última linha se buffer não é nulo
        char *line = ft_copy_until(buffer, ft_strlen(buffer) - 1);
        free(buffer);
        buffer = NULL;
        return line;
    }

    free(buffer);
    buffer = NULL; // Garante que o buffer seja limpo
    return NULL;
}