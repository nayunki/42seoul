/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:04:15 by naki              #+#    #+#             */
/*   Updated: 2022/07/23 19:37:09 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					n;
	unsigned long long	res;

	n = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			n *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (*str - '0') + (res * 10);
		str++;
	}
	if (res > 9223372036854775807 && n == -1)
		return (0);
	else if (res > 9223372036854775807)
		return (-1);
	else
		return (n * (int)res);
}
