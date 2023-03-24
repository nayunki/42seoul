/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 02:29:30 by naki              #+#    #+#             */
/*   Updated: 2023/03/24 09:09:22 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_safe_malloc(size_t	size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
	{
		write(2, "malloc failed\n", 14);
		exit (1);
	}
	// while (size-- > 0)
	// 	((unsigned char*)ret)[size] = 0;
	return (ret);
}

int	ft_atoi(const char *str)
{
	int					n;
	unsigned long long	res;

	n = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			n *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (*str - '0') + (res * 10);
		str++;
	}
	return (n * (int)res);
}

int	now_time(void)
{
	struct timeval	time;
	long			sec;
	int				usec;

	gettimeofday(&time, NULL);
	sec = time.tv_sec;
	usec = time.tv_usec;
	return (sec * 1000 + usec / 1000); //milisecond로 변환
}

void	philo_printf(t_info *info, t_philo *philo, t_type type)
{
	pthread_mutex_lock(&(info->m_print)); //finish flag올린거 확인되면 바로 리턴
	if (info->finish_flag == 1 || type == GOAL)
	{
		if (type == GOAL)
			printf("every philosopher has eaten %d times\n", info->must_eat);
		info->finish_flag = 1;
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
	if (type == DIE)
		info->finish_flag = 1;
	pthread_mutex_unlock(&(info->m_print));
}

void	psleep(int time) // 단위 맞추다가 int 범위 벗어나면 어케요 ?
{
	const int	target_time = now_time() + time; // 목표 시간 정해놓고

	while (now_time() < target_time) // 될 때까지 유슬립
		usleep(100);
}
//usleep : microseconds, time : miliseconds
//microseconds * 10^3 == miliseconds
