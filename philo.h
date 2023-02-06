#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct	s_rules
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}				t_rules;

typedef struct	s_philo
{
	int				id;
	t_rules			*rules;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}				t_philo;

typedef struct	s_data
{
	t_rules *rules;
	t_philo *philo_array;
	int		number_of_chair;
}				t_data;

t_data	*inti_rulse(t_data *data, int ttd, int tte,int tts);
t_data	*init_philo(t_data *data, int number_of_chair);

#endif
