/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:31:25 by naki              #+#    #+#             */
/*   Updated: 2023/01/28 16:46:03 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_byte(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit) & 1)
			kill(pid, 31);
		else
			kill(pid, 30);
		usleep(500);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	i = 0;
	if (ac != 3)
		return (0);
	pid = ft_atoi(av[1]);
	if (pid < 100 || 99999 < pid)
		return (0);
	while (av[2][i])
	{
		send_byte(pid, av[2][i]);
		i++;
	}
	return (0);
}
