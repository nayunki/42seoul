/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:29:08 by naki              #+#    #+#             */
/*   Updated: 2023/03/20 02:23:14 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_printf(t_info *info, t_philo *philo, t_type type)
{
	pthread_mutex_lock(&(info->m_print));
	if (type == GOAL)
	{
		printf("every philosopher has eaten %d times\n", info->must_eat);
		pthread_mutex_unlock(&(info->m_print));
		return ;
	}
	printf("%dms ", now_time() - info->start_time);
	printf("philo %d ", philo->id + 1);
	if (type == FORK)
		printf("has taken a fork\n");
	else if (type == EAT)
		printf("is eating\n");
	else if (type == SLEEP)
		printf("is sleeping\n");
	else if (type == THINK)
		printf("is thinking\n");
	else if (type == DIE)
		printf("died\n");
	pthread_mutex_unlock(&(info->m_print));
}

// void	do_philo_one()
// {

// }

//usleep : microseconds, time : miliseconds
//microseconds * 10^3 == miliseconds
void	psleep(int time) // 단위 맞추다가 int 범위 벗어나면 어케요 ?
{
	int	i;

	i = 0;
	while (i < 10)
	{
		usleep(time * 100); //usleep 10번으로 나눔
		i++;
	}
	return ;
}

int	check_die(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&(info->m_die));
	if (now_time() - philo->last_eat >= info->time_die)
	{
		info->die_flag = 1;
		pthread_mutex_unlock(&(info->m_die));
		return (1);
	}
	pthread_mutex_unlock(&(info->m_die));
	return (0);
}

void	eat(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork));
	pthread_mutex_lock(&(philo[((philo->id + 1) % info->philo_num)].fork));
	philo_printf(info, philo, FORK);
	philo_printf(info, philo, EAT);
	philo->last_eat = now_time();
	psleep(info->time_eat);
	philo->eat_count++;
	pthread_mutex_unlock(&(philo->fork));
	pthread_mutex_unlock(&(philo[((philo->id + 1) % info->philo_num)].fork));
}

void	philo_act(t_philo *philo)
{
	if (philo->id % 2 == 0)
		psleep(philo->info->time_eat);
	while (1)
	{
		if (check_die(philo->info, philo))
			return ;
		eat(philo->info, philo);
		philo_printf(philo->info, philo, SLEEP);
		psleep(philo->info->time_sleep);
		philo_printf(philo->info, philo, THINK);
	}
}
