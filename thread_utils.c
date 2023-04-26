/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:14:42 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/26 13:29:22 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <unistd.h>

int p_say(t_philo *philo, char *str)
{
	int id;
	long long	ts;

	id = philo->id;
	ts = (get_time() - philo->rules->time_sim_start);
	pthread_mutex_lock(philo->mutex->say);
	printf("Timetamp: %lld | ID: %i | Say: %s \n", ts, id, str);
	pthread_mutex_unlock(philo->mutex->say);
	return (0);
}

int take_fork(t_philo *current_philo)
{
	pthread_mutex_lock(current_philo->left_fork);
	p_say(current_philo, "Has taken a fork");
	pthread_mutex_lock(current_philo->right_fork);
	p_say(current_philo, "Has taken a fork");
	return (0);
}

int sleep_in_my_bed(t_philo *current_philo)
{

}

int wankil(t_philo *current_philo)
{

}

int	eat(t_philo *current_philo)
{
	long long current_time;

	p_say(current_philo, "Is eating");
	current_time = get_time();
	while ((get_time() - current_time) < current_philo->rules->time_to_eat)
		usleep(500);
	usleep()
	
}
