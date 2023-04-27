/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:44:28 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/27 11:19:19 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

t_data	*destroy_mutex(t_data *data)
{
	if (data->mutex)
	{
		pthread_mutex_destroy(data->mutex->say);
		pthread_mutex_destroy(data->mutex->is_alive);
		free(data->mutex->say);
		free(data->mutex->is_alive);
		free(data->mutex);
	}
	return (data);
}

t_data	*destroy_philo(t_data *data, int number_of_philo)
{
	int	index;

	index = 0;
	if (data->number_of_chair)
		free(data->philo_array[0].alive);
	while (index < number_of_philo)
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
