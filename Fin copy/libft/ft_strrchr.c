/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:09:35 by naki              #+#    #+#             */
/*   Updated: 2022/07/24 00:54:48 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len)
	{
		if (s[len] == (char)c)
			return ((char *)s + len);
		len--;
	}
	if (s[len] == (char)c)
		return ((char *)s + len);
	return (NULL);
}
