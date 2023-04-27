/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:21:47 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/27 18:06:52 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_rules
{
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	//int			number_of_meals;
	long long	time_sim_start;
}				t_rules;

typedef struct s_mutex
{
	pthread_mutex_t	*say;
	pthread_mutex_t	*is_alive;
}				t_mutex;

typedef struct s_philo
{
	int				id;
	long long		last_meal;
	//int				end;
	int				*alive;
	t_rules			*rules;
	t_mutex			*mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	//pthread_mutex_t	meal_cmp;
	pthread_mutex_t	mutex_last_meal;
	pthread_t		thread;
}				t_philo;

typedef struct s_data
{
	t_rules		rules;
	t_mutex		*mutex;
	t_philo		*philo_array;
	pthread_t	supervisor;
	int			number_of_chair;
}				t_data;

long long	get_time(void);


int			check_pars(int input_size, char **input);
int			ft_atoi(const char *nptr);
int			drop_fork(t_philo *current_philo);
int			take_fork(t_philo *current_philo);
int			p_say(t_philo *philo, char *str);
int			p_sleep(t_philo *current_philo, int rules);
int			check_dead_status(t_philo *current_philo);
int			set_dead_status(t_philo *current_philo);
int			eat(t_philo *current_philo);
int			wankil(t_philo *current_philo);
int			sleep_in_my_bed(t_philo *current_philo);
int			take_fork(t_philo *current_philo);
t_data		*init_rules(t_data *data, int ttd, int tte, int tts);
t_data		*init_philo(t_data *data, int number_of_chair);
t_data		*philo_creat(t_data *data);
t_data		*start_routine(t_data *data);
t_data		*destroy_mutex(t_data *data);
t_data		*destroy_thread(t_data *data, int number_of_thread);
t_data		*destroy_philo(t_data *data, int number_of_philo);
void		meal_cmp(t_philo *current_philo, int i);
void		*thread_routine(void *philo);
void		*supervisor_routine(void *data);

#endif
