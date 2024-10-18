/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malopes- <malopes-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:37:59 by malopes-          #+#    #+#             */
/*   Updated: 2024/10/18 15:55:24 by malopes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_copy_from(char *src, int n) {
    char *dest;
    int i;
    
    dest = (char *)malloc(sizeof(char) * (strlen(src + n) + 1));
    if (!dest)
        return NULL;
    i = 0;
    while (src[n + i] != '\0') {
        dest[i] = src[n + i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *ft_copy_until(char *src, int n) {
    char *dest;
    int i;

    // Aloca memória para a linha, incluindo o '\n'
    dest = (char *)malloc(sizeof(char) *(n + 2)); // n + 1 para o '\n' e +1 para o '\0'
    if (!dest)
        return NULL;
    i = 0;
    while (i <= n) {  // Agora incluímos o caractere '\n'
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  // Termina a string
    return dest;
}

int     ft_strlen(char *s) {
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}
char *ft_strjoin(char *s1, char *s2) {
    int len1;
    int len2;
    char *result;
    int i;

    if (!s1)
        s1 = ft_strdup("");
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    result = (char *)malloc(sizeof(char) * ((len1 + len2) + 1));
    if (!result)
        return NULL;
    i = 0;
    while (i < len1) {
        result[i] = s1[i];
        i++;
    }
    i = 0;
    while (i < len2) {
        result[len1 + i] = s2[i];
        i++;
    }
    result[len1 + len2] = '\0';
    free(s1); // Libera o buffer antigo
    return result;
}


char *ft_strdup(const char *src) {
    int len = ft_strlen((char *)src);
    char *dup = (char *)malloc(sizeof(char) *(len + 1));
    if (!dup)
        return NULL;
    for (int i = 0; i < len; i++)
        dup[i] = src[i];
    dup[len] = '\0';
    return dup;
}
