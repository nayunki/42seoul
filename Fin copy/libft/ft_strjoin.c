/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:13:19 by naki              #+#    #+#             */
/*   Updated: 2022/07/24 04:21:45 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	strjoin = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!strjoin)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		strjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		strjoin[i] = s2[j];
		i++;
		j++;
	}
	strjoin[i] = '\0';
	return (strjoin);
}
