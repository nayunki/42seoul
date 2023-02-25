/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:25:54 by naki              #+#    #+#             */
/*   Updated: 2022/07/23 23:17:41 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (len);
	while (dstsize - 1 && i < len)
	{
		*dst = (char)*src;
		dst++;
		src++;
		dstsize--;
		i++;
	}
	*dst = '\0';
	return (len);
}
