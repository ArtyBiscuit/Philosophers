/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:15:07 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/26 12:42:08 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

long long	get_time()
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	dead(t_philo *current_philo, long long current_time)
{
	if (*current_philo->alive == 0)
		return (1);
	if (current_time > current_philo->rules->time_to_eat)
	{
		pthread_mutex_lock(current_philo->mutex->is_alive);
		*current_philo->alive = 0;
		pthread_mutex_unlock(current_philo->mutex->is_alive);
		return (1);
	}
	return (0);
}

int	p_sleep(t_philo *current_philo)
{
	long long current_time;

	current_time = get_time();
	while ((get_time() - current_time) < current_philo->rules->time_to_eat)
		usleep(500);
	if(dead(current_philo, current_time))
		return (1);
	current_philo->last_mile = get_time();
	
	return (0);
}
