/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:36:03 by arforgea          #+#    #+#             */
/*   Updated: 2023/02/09 17:00:32 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <pthread.h>
#include <unistd.h>

t_data	*start_routine(t_data *data)
{
	int index;
	t_philo	philo;

	index = 0;
	while (index < data->number_of_chair)
	{
		philo = data->philo_array[index];
		if (pthread_create(&philo.thread, NULL, thread_routine, &philo))
		{
			destroy_philo(data, index);
			write(2, "Error: start_routine.\n", 22);
			return (NULL);
		}
		index++;
	}
	return (data);
}
