/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 03:52:14 by naki              #+#    #+#             */
/*   Updated: 2022/07/24 04:26:56 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*arr;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	arr = malloc(len + 1);
	if (!arr)
		return (NULL);
	j = 0;
	while (s[i])
	{
		arr[j] = f(i, s[i]);
		i++;
		j++;
	}
	arr[j] = '\0';
	return (arr);
}
