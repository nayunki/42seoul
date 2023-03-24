/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:29:11 by naki              #+#    #+#             */
/*   Updated: 2023/03/24 06:48:10 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_die(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
	{
		pthread_mutex_lock(&(philo[i].m_last_eat));
		if (now_time() - philo[i].last_eat > info->time_die)
		{
			philo_printf(info, &philo[i], DIE);
			pthread_mutex_unlock(&(philo[i].m_last_eat));
			return (1);
		}
		pthread_mutex_unlock(&(philo[i].m_last_eat));
		i++;
	}
	return (0);
}

int	check_full(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	if (info->must_eat == -1)
		return (0);
	while (i < info->philo_num)
	{
		pthread_mutex_lock(&(philo[i].m_eat_count));
		if (philo[i].eat_count < info->must_eat)
		{
			philo_printf(info, &philo[i], GOAL);
			pthread_mutex_unlock(&(philo[i].m_eat_count));
			return (0);
		}
		pthread_mutex_unlock(&(philo[i].m_eat_count));
		i++;
	}
	return (1);
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
		if (check_die(info, philo_info) || check_full(info, philo_info))
		{
			destroy_all(info, philo_info);
			break ;
		}
	}
	return (0);
}
