/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:15:07 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/27 11:35:41 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <bits/time.h>
#include <pthread.h>

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	set_dead_status(t_philo *current_philo)
{
	pthread_mutex_lock(current_philo->mutex->is_alive);
	*current_philo->alive = 0;
	pthread_mutex_unlock(current_philo->mutex->is_alive);
	return (1);
}

int	check_dead_status(t_philo *current_philo)
{
	pthread_mutex_lock(current_philo->mutex->is_alive);
	if (*current_philo->alive == 0)
	{
		p_say(current_philo, "oh no i'm dead!");
		pthread_mutex_unlock(current_philo->mutex->is_alive);
		return (1);
	}
	pthread_mutex_unlock(current_philo->mutex->is_alive);
	return (0);
}

int	p_sleep(t_philo *philo, int rules)
{
	long long	current_time;
	long long	dead_time;

	current_time = get_time();
	while ((get_time() - current_time) < rules)
	{
		if (check_dead_status(philo))
			return (1);
		usleep(500);
		dead_time = get_time();
		if ((dead_time - philo->last_meal) > philo->rules->time_to_die)
		{
			set_dead_status(philo);
			return (1);
		}
	}
	return (0);
}
