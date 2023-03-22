/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:07:30 by naki              #+#    #+#             */
/*   Updated: 2022/07/30 15:43:40 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *str, char c)
{
	int	wd;
	int	i;

	wd = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (!str[i])
			break ;
		wd++;
		while (str[i] != c && str[i])
			i++;
	}
	return (wd);
}

static int	word_size(char const *str, char c, int i)
{
	int	len;

	len = 0;
	while (str[i + len] != c && str[i + len])
		len++;
	return (len);
}

static char	**free_all(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	*put_str(char const *str, char c, int i)
{
	int		j;
	char	*arr;

	arr = malloc(word_size(str, c, i) + 1);
	if (!arr)
		return (NULL);
	j = 0;
	while (str[i + j] != c && str[i + j])
	{
		arr[j] = str[i + j];
		j++;
	}
	arr[j] = '\0';
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		split[j] = put_str(s, c, i);
		if (!split[j++])
			return (free_all(split));
		while (s[i] != c && s[i])
			i++;
	}
	split[j] = NULL;
	return (split);
}
