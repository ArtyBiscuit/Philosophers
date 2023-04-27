/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:14:42 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/27 11:35:15 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	p_say(t_philo *philo, char *str)
{
	int			id;
	long long	ts;

	id = philo->id;
	ts = (get_time() - philo->rules->time_sim_start);
	pthread_mutex_lock(philo->mutex->say);
	printf("Timetamp: %lld | ID: %i | Say: %s \n", ts, id, str);
	pthread_mutex_unlock(philo->mutex->say);
	return (0);
}

int	drop_fork(t_philo *current_philo)
{
	pthread_mutex_unlock(current_philo->left_fork);
	pthread_mutex_unlock(current_philo->right_fork);
	return (0);
}

int	take_fork(t_philo *current_philo)
{
	pthread_mutex_lock(current_philo->left_fork);
	if (check_dead_status(current_philo))
	{
		pthread_mutex_unlock(current_philo->left_fork);
		return (1);
	}
	p_say(current_philo, "Has taken a fork");
	pthread_mutex_lock(current_philo->right_fork);
	if (check_dead_status(current_philo))
	{
		drop_fork(current_philo);
		return (1);
	}
	p_say(current_philo, "Has taken a fork");
	return (0);
}
