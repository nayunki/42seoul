/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:08:36 by naki              #+#    #+#             */
/*   Updated: 2023/01/02 13:26:01 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(unsigned long nb, char type)
{
	if (0 <= nb && nb <= 9)
		ft_putchar_fd(nb + '0', 1);
	else if (10 <= nb && nb <= 15)
	{
		if (type == 'x')
			ft_putchar_fd(nb + 'a' - 10, 1);
		else if (type == 'X')
			ft_putchar_fd(nb + 'A' - 10, 1);
	}
}

int	ft_putnbr_hex(unsigned long nb, char type)
{
	int	len;

	len = 0;
	if (nb > 15)
	{
		len += ft_putnbr_hex(nb / 16, type);
		len += ft_putnbr_hex(nb % 16, type);
	}
	else
	{
		print_hex(nb, type);
		len++;
	}
	return (len);
}

int	ft_putpointer(void *p)
{
	unsigned long	u;
	int				len;

	u = (unsigned long)p;
	len = 0;
	len += ft_putstr_fd("0x", 1);
	len += ft_putnbr_hex(u, 'x');
	return (len);
}

int	ft_putunsigned(unsigned int u)
{
	int	len;

	len = 0;
	if (u > 9)
	{
		len += ft_putunsigned(u / 10);
		len += ft_putunsigned(u % 10);
	}
	else
		len += ft_putchar_fd(u + '0', 1);
	return (len);
}
