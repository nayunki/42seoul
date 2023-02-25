/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:13:01 by naki              #+#    #+#             */
/*   Updated: 2022/07/15 17:22:28 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp_s;

	temp_s = (unsigned char *)s;
	while (n--)
	{
		if (*temp_s == (unsigned char)c)
			return (temp_s);
		temp_s++;
	}
	return (NULL);
}
