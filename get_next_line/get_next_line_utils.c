/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:14:27 by naki              #+#    #+#             */
/*   Updated: 2022/10/10 22:16:47 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_calloc(size_t count)
{
	char			*arr;
	unsigned char	*temp;

	arr = malloc(count);
	if (!arr)
		return (NULL);
	temp = (unsigned char *)arr;
	while (count)
	{
		*temp = 0;
		temp++;
		count--;
	}
	return (arr);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if ((s[i]) == (char)c)
		return (i);
	return (-1);
}

char	*ft_strjoin(char *s1, char const *s2, size_t len)
{
	char	*strjoin;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	strjoin = malloc (ft_strlen(s1) + len + 1);
	if (!strjoin)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len)
	{
		strjoin[i] = s2[j];
		i++;
		j++;
	}
	strjoin[i] = '\0';
	free (s1);
	return (strjoin);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_d;
	unsigned char	*temp_s;

	temp_d = (unsigned char *)dst;
	temp_s = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	while (n)
	{
		*temp_d = *temp_s;
		temp_d++;
		temp_s++;
		n--;
	}
	return (dst);
}
