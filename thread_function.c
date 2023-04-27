/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:30:47 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/27 18:08:44 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>

int	sleep_in_my_bed(t_philo *current_philo)
{
	p_say(current_philo, "Is sleeping");
	if(p_sleep(current_philo, current_philo->rules->time_to_sleep))
		return (1);
	return (0);
}

int	wankil(t_philo *current_philo)
{
	p_say(current_philo, "Is thinking");
	if(check_dead_status(current_philo))
		return (1);
	return (0);
}
/*
void	meal_cmp(t_philo *current_philo, int i)
{
	if (i == current_philo->rules->number_of_meals)
	{
		pthread_mutex_lock(&current_philo->meal_cmp);
		current_philo->end = 1;
		pthread_mutex_unlock(&current_philo->meal_cmp);
	}
}
*/
int	eat(t_philo *current_philo)
{
	long long	current_time;

	p_say(current_philo, "Is eating");
	pthread_mutex_lock(&current_philo->mutex_last_meal);
	current_philo->last_meal = get_time();
	pthread_mutex_unlock(&current_philo->mutex_last_meal);
	if(p_sleep(current_philo, current_philo->rules->time_to_eat))
	{
		drop_fork(current_philo);
		return (1);
	}
	drop_fork(current_philo);
	return (0);
}
