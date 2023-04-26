#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
#include <sys/time.h>


typedef struct	s_rules
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	long long	time_sim_start;
}				t_rules;

typedef struct	s_mutex
{
	pthread_mutex_t	*say;
	pthread_mutex_t	*is_alive;
}				t_mutex;

typedef struct	s_philo
{
	int				id;
	long long		last_mile;
	int				*alive;
	t_rules			*rules;
	t_mutex			*mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
}				t_philo;

typedef struct	s_data
{
	t_rules 	rules;
	t_mutex		*mutex;
	t_philo 	*philo_array;
	int			number_of_chair;
}				t_data;

long long	get_time();


t_data	*init_rules(t_data *data, int ttd, int tte,int tts);
t_data	*init_philo(t_data *data, int number_of_chair);

t_data	*philo_creat(t_data *data);

t_data	*start_routine(t_data *data);

t_data	*destroy_mutex(t_data *data);
t_data	*destroy_thread(t_data *data, int number_of_thread);
t_data	*destroy_philo(t_data *data, int number_of_philo);

void	*thread_routine(void *philo);
#endif
