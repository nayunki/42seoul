/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:17:15 by naki              #+#    #+#             */
/*   Updated: 2022/08/01 12:43:23 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static void	ft_putstr(const char *s1, char *strtrim, int start, int end)
{
	int	i;

	i = 0;
	while (start <= end)
	{
		strtrim[i] = s1[start];
		start++;
		i++;
	}
	strtrim[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*strtrim;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (check_set(s1[start], set) && s1[start])
		start++;
	if (s1[start] == '\0')
	{
		strtrim = malloc(1);
		if (!strtrim)
			return (NULL);
		*strtrim = '\0';
		return (strtrim);
	}
	while (check_set(s1[end], set) && end > start)
		end--;
	strtrim = malloc(end - start + 2);
	if (!strtrim)
		return (NULL);
	ft_putstr(s1, strtrim, start, end);
	return (strtrim);
}
