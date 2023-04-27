/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:36:03 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/27 11:20:00 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

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
	index = 0;
	while (index < data->number_of_chair)
	{
		pthread_join(data->philo_array[index].thread, NULL);
		index ++;
	}
	return (data);
}
