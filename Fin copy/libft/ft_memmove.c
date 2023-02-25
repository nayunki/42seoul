/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:35:42 by naki              #+#    #+#             */
/*   Updated: 2022/07/23 22:14:55 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_d;
	unsigned char	*temp_s;

	temp_d = (unsigned char *)dst;
	temp_s = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len-- > 0)
			*(temp_d + len) = *(temp_s + len);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
