/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:29:08 by naki              #+#    #+#             */
/*   Updated: 2023/03/24 10:48:25 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	update_last_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->m_last_eat));
	philo->last_eat = now_time();
	pthread_mutex_unlock(&(philo->m_last_eat));
}

static void	update_eat_count(t_philo *philo)
{
	pthread_mutex_lock(&(philo->m_eat_count));
	philo->eat_count++;
	pthread_mutex_unlock(&(philo->m_eat_count));
}

static pthread_mutex_t	*get_first_fork(t_info *info, t_philo *philo)
{
	if (philo->id % 2 == 0) // 필로 인덱스에 따라 잡는 순서 달라짐
		return (&(philo->fork));
	else if (philo->id + 1 != info->philo_num)
		return (&(philo[1].fork)); // 현재 주소값의 다음 거
	else
		return (&(philo[-philo->id].fork)); // 말을 정리해놓기
}

static pthread_mutex_t	*get_second_fork(t_info *info, t_philo *philo)
{
	if (philo->id % 2 == 1)
		return (&(philo->fork));
	else if (philo->id + 1 != info->philo_num)
		return (&(philo[1].fork));
	else
		return (&(philo[-philo->id].fork));
}

void	eat(t_info *info, t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	first = get_first_fork(info, philo);
	second = get_second_fork(info, philo);
	pthread_mutex_lock(first);
	philo_printf(info, philo, FORK);
	pthread_mutex_lock(second);
	philo_printf(info, philo, EAT);
	update_last_eat(philo);
	update_eat_count(philo);
	psleep(info->time_eat);
	pthread_mutex_unlock(second);
	pthread_mutex_unlock(first);
}
