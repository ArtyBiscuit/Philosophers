/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:44:28 by arforgea          #+#    #+#             */
/*   Updated: 2023/02/09 16:57:21 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <pthread.h>

t_data	*destroy_philo(t_data *data, int number_of_philo)
{
	int	index;

	index = 0;
	while(index < number_of_philo)
	{
		if (data->philo_array[index].right_fork)
		{
			pthread_mutex_destroy(data->philo_array[index].right_fork);
			free(data->philo_array[index].right_fork);
			data->philo_array[index].right_fork = NULL;
			data->philo_array[index].left_fork = NULL;
		}
		index++;
	}
	if (index < data->number_of_chair)
		data->philo_array[index].left_fork = NULL;
	return (data);
}

t_data	*destroy_thread(t_data *data, int number_of_thread)
{
	int index;

	index = 0;
	while(index < number_of_thread)
	{
		index++;
	}
	return (NULL);
}
