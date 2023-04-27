/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:36:03 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/27 15:18:53 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>

static void	join_all(t_data *data)
{
	int index;

	index = 0;
	pthread_join(data->supervisor, NULL);
	while (index < data->number_of_chair)
	{
		pthread_join(data->philo_array[index].thread, NULL);
		index++;
	}
}

t_data	*start_routine(t_data *data)
{
	int		index;
	t_philo	*philo;

	index = 0;
	data->rules.time_sim_start = get_time();
	while (index < data->number_of_chair)
	{
		data->philo_array[index].last_meal = get_time();
		philo = &(data->philo_array[index]);
		if (pthread_create(&philo->thread, NULL, thread_routine, philo))
		{
			destroy_philo(data, index);
			write(2, "Error: start_routine.\n", 22);
			return (NULL);
		}
		index++;
	}
	pthread_create(&data->supervisor, NULL, supervisor_routine, data);
	join_all(data);
	return (data);
}
