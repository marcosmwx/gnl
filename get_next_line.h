/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malopes- <malopes-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:38:08 by malopes-          #+#    #+#             */
/*   Updated: 2024/10/17 14:38:11 by malopes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

//# define BUFFER_SIZE 10000000

char    *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_copy_from(char *src, int n);
char    *ft_copy_until(char *src, int n);
int     ft_strlen(const char *s);
char *ft_strdup(const char *src);

#endif

