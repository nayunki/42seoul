/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:29:11 by naki              #+#    #+#             */
/*   Updated: 2023/03/20 02:32:15 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitoring(t_info *info, t_philo *philo)
{
	int	i;

	while (1)
	{
		pthread_mutex_lock(&(info->m_die));
		if (info->die_flag == 1)
		{
			philo_printf(info, philo, DIE);
			return (1);
		}
		pthread_mutex_unlock(&(info->m_die));
		if (info->must_eat != -1)
		{
			i = 0;
			while (i < info->philo_num)
			{
				if (info->must_eat != philo->eat_count)
					break ;
				i++;
			}
			if (i == info->must_eat)
			{
				philo_printf(info, philo, GOAL);
				pthread_mutex_unlock(&(philo->fork));
				return (1);
			}
		}
	}
}

int	main(int ac, char **av)
{
	pthread_t	*philos;
	t_philo		*philo_info;
	t_info		*info;

	if (ac != 5 && ac != 6)
		return (1);
	info = ft_safe_malloc(sizeof(t_info));
	if (!init_info(ac, av, info))
		return (1);
	philos = ft_safe_malloc(sizeof(pthread_t) * info->philo_num);
	philo_info = ft_safe_malloc(sizeof(t_philo) * info->philo_num);
	if (!init_mutex(info, philo_info))
		return (1);
	if (!init_philos(philo_info, info, philos))
		return (1);
	while (1)
	{
		if (monitoring(info, philo_info))
		{
			destroy_all(info, philo_info);
			return (0);
		}
	}
	return (0);
}
