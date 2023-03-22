/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:25:49 by naki              #+#    #+#             */
/*   Updated: 2023/03/20 01:55:54 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_info(int ac, char **av, t_info *info)
{
	info->philo_num = ft_atoi(av[1]);
	info->time_die = ft_atoi(av[2]);
	info->time_eat = ft_atoi(av[3]);
	info->time_sleep = ft_atoi(av[4]);
	info->start_time = now_time();
	info->die_flag = 0;
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	else
		info->must_eat = -1;
	if (info->philo_num <= 0 || info->time_die <= 0 || info->time_eat <= 0 || \
		info->time_sleep <= 0 || info-> must_eat < -1)
		return (0);
	return (1);
}

int	init_philos(t_philo *philo_info, t_info *info, pthread_t *philos)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
	{
		philo_info[i].id = i;
		philo_info[i].eat_count = 0;
		philo_info[i].last_eat = now_time();
		philo_info[i].info = info;
		i++;
	}
	i = 0;
	while (i < info->philo_num)
	{
		// if (info->philo_num == 1)
		// 	do_philo_one();
		if (pthread_create(&(philos[i]), NULL, (void *)philo_act, &(philo_info[i])))
			return (0);
		if (pthread_detach(philos[i])) //이거왜함
			return (0);
		i++;
	}
	return (1);
}

int	init_mutex(t_info *info, t_philo *philo_info)
{
	int	i;

	if (pthread_mutex_init(&(info->m_print), NULL) < 0)
		return (0);
	if (pthread_mutex_init(&(info->m_die), NULL) < 0)
		return (0);
	i = 0;
	while (i < info->philo_num)
	{
		if (pthread_mutex_init(&(philo_info[i].fork), NULL) < 0)
			return (0);
		i++;
	}
	return (1);
}
