/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 04:26:29 by naki              #+#    #+#             */
/*   Updated: 2022/07/24 01:34:15 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_number(int a, int fd)
{
	char	b;

	b = a + '0';
	write(fd, &b, 1);
}

void	lessening(int nb, int fd)
{
	int	div;

	div = 1;
	while (nb / div >= 10)
		div = div * 10;
	while (nb >= 0)
	{
		print_number(nb / div, fd);
		nb = nb - (nb / div) * div;
		div = div / 10;
		if (div < 1)
			return ;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	lessening(n, fd);
}
