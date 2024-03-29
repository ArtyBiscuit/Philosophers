/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:30:50 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/27 18:05:30 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	*thread_routine(void *philo)
{
	//int		i;
	t_philo	*current_philo;

	current_philo = (t_philo *)philo;
	if (current_philo->id % 2)
		usleep(500);

	//i = 0;
	while (1)
	{
		if (take_fork(philo))
			break;
		if (eat(philo))
			break;
		//i++;
		//meal_cmp(philo, i);
		if (sleep_in_my_bed(philo))
			break;
		if (wankil(philo))
			break;
	}
	return (NULL);
}
