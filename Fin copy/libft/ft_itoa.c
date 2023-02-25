/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:40:13 by naki              #+#    #+#             */
/*   Updated: 2022/07/24 01:00:25 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit(long long n)
{
	int	digit;

	digit = 1;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static void	put_arr(char *arr, long long nb, int i)
{
	if (nb == 0)
		arr[i] = nb + 48;
	while (nb >= 1)
	{
		arr[i] = (nb % 10) + 48;
		nb /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char		*itoa;
	int			i;
	long long	nb;

	nb = (long long)n;
	if (nb < 0)
	{
		itoa = malloc(ft_digit(nb) + 2);
		if (!itoa)
			return (NULL);
		nb *= -1;
		itoa[0] = '-';
		i = ft_digit(nb) + 1;
	}
	else
	{
		itoa = malloc(ft_digit(nb) + 1);
		if (!itoa)
			return (NULL);
		i = ft_digit(nb);
	}
	itoa[i] = '\0';
	i--;
	put_arr(itoa, nb, i);
	return (itoa);
}
