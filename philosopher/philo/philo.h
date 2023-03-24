/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 05:27:31 by naki              #+#    #+#             */
/*   Updated: 2023/03/24 10:48:28 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>

typedef enum e_type
{
	FORK,
	DIE,
	GOAL,
	EAT,
	SLEEP,
	THINK
}	t_type;

typedef struct s_info
{
	int				philo_num;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	int				start_time;
	int				finish_flag;
	pthread_mutex_t	m_print;
}	t_info;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	int				last_eat;
	pthread_mutex_t	m_eat_count; // 다먹었는지 확인 vs 다 먹은거 추가
	pthread_mutex_t	m_last_eat; // 죽었는지 확인 vs 정보 업데이트
	pthread_mutex_t	fork;
	t_info			*info;
}	t_philo;

/*init.c*/
int		init_info(int ac, char **av, t_info *info);
int		init_philos(t_philo *philo_info, t_info *info, pthread_t *philos);
int		init_mutex(t_info *info, t_philo *philo_info);

/*philo.c*/
void	psleep(int time);
void	eat(t_info *info, t_philo *philo);
void	*philo_act(void *arg);

/*philo_utils.c*/
void	*ft_safe_malloc(size_t	size);
int		ft_atoi(const char *str);
int		now_time(void);
void	philo_printf(t_info *info, t_philo *philo, t_type type);
void	destroy_all(t_info *info, t_philo *philo);

/*main.c*/
int		check_die(t_info *info, t_philo *philo);
int		check_full(t_info *info, t_philo *philo);
int		main(int ac, char **av);

#endif
