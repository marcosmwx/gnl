/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malopes- <malopes-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:37:59 by malopes-          #+#    #+#             */
/*   Updated: 2024/10/21 10:19:01 by malopes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*dup;

	i = -1;
	if (!src)
		return (NULL);
	len = ft_strlen(src);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (src[++i] != '\0')
		dup[i] = src[i];
	dup[len] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*result;
	int		i;

	if (!s2)
		return (s1);
	if (!s1)
		s1 = ft_strdup("");
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * ((len1 + len2) + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < len1)
		result[i] = s1[i];
	i = -1;
	while (++i < len2)
		result[len1 + i] = s2[i];
	result[len1 + len2] = '\0';
	free(s1);
	return (result);
}

char	*ft_copy_until(char *src, int n)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (n + 2));
	if (!dest)
		return (NULL);
	i = 0;
	while (i <= n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_copy_from(char *src, int n)
{
	char	*dest;
	int		i;

	if (src == NULL || src[n] == '\0')
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(src + n) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[n + i] != '\0')
	{
		dest[i] = src[n + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
