/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:14:42 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/27 17:00:54 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	p_say(t_philo *philo, char *str)
{
	int			id;
	long long	ts;

	id = philo->id;
	if (!check_dead_status(philo))
	{
		pthread_mutex_lock(philo->mutex->say);
		ts = (get_time() - philo->rules->time_sim_start);
		printf("%lld\t| %i\t| %s \n", ts, id, str);
		pthread_mutex_unlock(philo->mutex->say);
	}
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
	p_say(current_philo, "Has taken a fork");
	pthread_mutex_lock(current_philo->right_fork);
	p_say(current_philo, "Has taken a fork");
	return (0);
}
