/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:18:50 by naki              #+#    #+#             */
/*   Updated: 2023/01/26 22:12:59 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		i;
	int		div;

	itoa = malloc(6);
	i = 0;
	div = 1;
	while (n / div >= 10)
		div *= 10;
	while (n >= 0)
	{
		itoa[i++] = n / div + '0';
		n = n - (n / div) * div;
		div /= 10;
		if (div < 1)
			break ;
	}
	itoa[i] = '\0';
	return (itoa);
}

int	ft_atoi(char *str)
{
	int	i;
	int	atoi;

	i = 0;
	atoi = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		else
			atoi = atoi * 10 + (str[i] - '0');
		i++;
	}
	return (atoi);
}
