#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>

typedef enum	e_type
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE,
	GOAL
}	t_type;

typedef struct	s_info
{
	int	philo_num;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	must_eat;
	int	start_time;
	int	die_flag;
	pthread_mutex_t	m_die;
	pthread_mutex_t	m_print;
}	t_info;

typedef	struct	s_philo
{
	int	id; // 밑에 두개도 뮤텍스로, 필로 내에 추가
	int	eat_count; // 다먹었는지 확인 vs 다 먹은거 추가
	int	last_eat; // 죽었는지 확인 vs 정보 업데이트
	pthread_mutex_t	fork;
	t_info	*info;
}	t_philo;

/*init.c*/
int		init_info(int ac, char **av, t_info *info);
int		init_philos(t_philo *philo_info, t_info *info, pthread_t *philos);
int		init_mutex(t_info *info, t_philo *philo_info);

/*philo.c*/
void	philo_printf(t_info *info, t_philo *philo, t_type type);
void	psleep(int time);
int		check_die(t_info *info, t_philo *philo);
void	eat(t_info *info, t_philo *philo);
void	philo_act(t_philo *philo);

/*philo_utils.c*/
void	*ft_safe_malloc(size_t	size);
int		ft_atoi(const char *str);
int		now_time(void);
void	destroy_all(t_info *info, t_philo *philo);

/*main.c*/
int		monitoring(t_info *info, t_philo *philo);
int		main(int ac, char **av);

#endif
