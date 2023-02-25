/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:29:13 by naki              #+#    #+#             */
/*   Updated: 2022/07/23 21:39:57 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
