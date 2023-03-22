/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:48:12 by naki              #+#    #+#             */
/*   Updated: 2023/01/26 21:03:40 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static int	bit;
	static char	byte;

	if (sig == 31)
		byte += (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &byte, 1);
		bit = 0;
		byte = 0;
	}
}

int	main(void)
{
	char	*pid_c;

	pid_c = ft_itoa(getpid());
	write(1, "PID : ", 6);
	write(1, pid_c, ft_strlen(pid_c));
	write(1, "\n", 1);
	signal(30, handler);
	signal(31, handler);
	while (1)
		pause();
	return (0);
}
