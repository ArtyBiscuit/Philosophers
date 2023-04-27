/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:15:07 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/27 16:16:31 by arforgea         ###   ########.fr       */
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
	if (*(current_philo->alive) == 0)
	{
		pthread_mutex_unlock(current_philo->mutex->is_alive);
		return (1);
	}
	pthread_mutex_unlock(current_philo->mutex->is_alive);
	return (0);
}

int	p_sleep(t_philo *philo, int rules)
{
	long long	current_time;

	current_time = get_time();
	while ((get_time() - current_time) < rules)
	{
		if (check_dead_status(philo))
			return (1);
		usleep(500);
	}
	return (0);
}
