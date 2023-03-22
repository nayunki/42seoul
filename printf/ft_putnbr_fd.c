/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 04:26:29 by naki              #+#    #+#             */
/*   Updated: 2022/12/09 21:57:45 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int		len;

	len = 0;
	if (n == -2147483648)
		len += write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		len += write(fd, "-", 1);
		n *= -1;
		len += ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		len += ft_putnbr_fd(n / 10, fd);
		len += ft_putnbr_fd(n % 10, fd);
	}
	else
		len += ft_putchar_fd(n + '0', fd);
	return (len);
}
