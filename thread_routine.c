/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:30:50 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/27 11:21:32 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	*thread_routine(void *philo)
{
	t_philo	*current_philo;

	current_philo = (t_philo *)philo;
	if (current_philo->id % 2)
		usleep(20000);
	while (1)
	{
		if (take_fork(philo))
			exit(1);
		if (check_dead_status(philo))
			exit(1);
		if (eat(philo))
			exit(1);
		if (check_dead_status(philo))
			exit(1);
		if (sleep_in_my_bed(philo))
			exit(1);
		if (check_dead_status(philo))
			exit(1);
		if (wankil(philo))
			exit(1);
		if (check_dead_status(philo))
			exit(1);
	}
	return (NULL);
}
