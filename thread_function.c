/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:30:47 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/27 11:34:32 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	sleep_in_my_bed(t_philo *current_philo)
{
	p_say(current_philo, "Is sleeping");
	if (p_sleep(current_philo, current_philo->rules->time_to_sleep))
		return (1);
	return (0);
}

int	wankil(t_philo *current_philo)
{
	p_say(current_philo, "Is thinking");
	if (check_dead_status(current_philo))
		return (1);
	return (0);
}

int	eat(t_philo *current_philo)
{
	long long	current_time;

	p_say(current_philo, "Is eating");
	if (p_sleep(current_philo, current_philo->rules->time_to_eat))
	{
		drop_fork(current_philo);
		return (1);
	}
	current_philo->last_meal = get_time();
	drop_fork(current_philo);
	return (0);
}
