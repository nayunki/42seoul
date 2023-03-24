/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:25:49 by naki              #+#    #+#             */
/*   Updated: 2023/03/24 10:50:17 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_act(void *arg)
{
	t_philo *philo;

	philo = arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (philo->info->finish_flag == 1)
			return (NULL);
		eat(philo->info, philo);
		philo_printf(philo->info, philo, SLEEP);
		psleep(philo->info->time_sleep);
		philo_printf(philo->info, philo, THINK);
		if (philo->info->philo_num % 2 != 0)
			usleep(1000);
	}
	return (NULL);
}

int	init_info(int ac, char **av, t_info *info)
{
	info->philo_num = ft_atoi(av[1]);
	info->time_die = ft_atoi(av[2]);
	info->time_eat = ft_atoi(av[3]);
	info->time_sleep = ft_atoi(av[4]);
	info->start_time = now_time();
	info->finish_flag = 0;
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
		pthread_mutex_lock(&(philo_info[i].m_eat_count));
		philo_info[i].eat_count = 0;
		pthread_mutex_unlock(&(philo_info[i].m_eat_count));
		pthread_mutex_lock(&(philo_info[i].m_last_eat));
		philo_info[i].last_eat = now_time();
		pthread_mutex_unlock(&(philo_info[i].m_last_eat));
		philo_info[i].info = info;
		i++;
	}
	i = 0;
	while (i < info->philo_num)
	{
		if (pthread_create(&(philos[i]), NULL, &philo_act, &(philo_info[i])))
			return (0);
		// if (pthread_join(philos[i], NULL))
		// 	return (0);
		if (pthread_detach(philos[i]))
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
	i = 0;
	while (i < info->philo_num)
	{
		if (pthread_mutex_init(&(philo_info[i].fork), NULL) < 0 || \
		pthread_mutex_init(&(philo_info[i].m_last_eat), NULL) < 0 || \
		pthread_mutex_init(&(philo_info[i].m_eat_count), NULL) < 0)
			return (0);
		i++;
	}
	return (1);
}
/*
detach 사용 시 main문 끝나면 destroy all 후 리턴되며 모든 스레드 종료되는데,
join 사용 시 스레드 각자가 die flag확인하고 주섬주섬 정리 ? ? ?
*/

// die flag 만들어서 스레드 하나 죽으면 다 알 수 있게 하기 ~ !
//-> 하나라도 죽으면 모두 종료시킨 뒤에 뮤텍스 destroy를 하게 하기 위해서
void	destroy_all(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
	{
		pthread_mutex_destroy(&(philo[i].fork));
		pthread_mutex_destroy(&(philo[i].m_last_eat));
		pthread_mutex_destroy(&(philo[i].m_eat_count));
		i++;
	}
	pthread_mutex_destroy(&(info->m_print));
}
