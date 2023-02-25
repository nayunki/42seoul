/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:03:44 by naki              #+#    #+#             */
/*   Updated: 2023/01/02 12:23:14 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parsing(const char c, va_list ap)
{
	int	len;

	len = 0;
	if (c == '%')
		len += ft_putchar_fd('%', 1);
	else if (c == 'c')
		len += ft_putchar_fd(va_arg(ap, int), 1);
	else if (c == 's')
		len += ft_putstr_fd(va_arg(ap, char *), 1);
	else if (c == 'p')
		len += ft_putpointer(va_arg(ap, void *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'u')
		len += ft_putunsigned(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_putnbr_hex(va_arg(ap, unsigned int), c);
	return (len);
}

int	ft_printf(const char *args, ...)
{
	va_list	ap;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!args)
		return (-1);
	va_start(ap, args);
	while (args[i])
	{
		if (args[i] == '%')
			len += parsing(args[++i], ap);
		else
			len += ft_putchar_fd(args[i], 1);
		++i;
	}
	va_end(ap);
	return (len);
}
