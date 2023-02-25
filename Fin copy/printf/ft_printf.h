/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:05:20 by naki              #+#    #+#             */
/*   Updated: 2022/12/18 17:40:38 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *args, ...);
int		parsing(char c, va_list ap);
void	print_hex(unsigned long nb, char type);
int		ft_putnbr_hex(unsigned long nb, char type);
int		ft_putpointer(void *p);
int		ft_putunsigned(unsigned int u);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
#endif
