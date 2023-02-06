/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inti_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:27:34 by arforgea          #+#    #+#             */
/*   Updated: 2023/02/06 19:15:35 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

t_data	*init_philo(t_data *data, int number_of_chair)
{
	int index;

	data->number_of_chair = number_of_chair;
	data->philo_array = malloc(sizeof(t_philo) * data->number_of_chair);
	if (!data->philo_array)
	{
		write(2, "Error: init_philo.\n", 19);
		return (NULL);
	}
	index = 0;
	while(index < data->number_of_chair)
	{
		data->philo_array[index].rules = data->rules;
		data->philo_array[index].id = index + 1;
		index++;
	}
	index = 0;
	while(index < data->number_of_chair)
	{
		pthread_mutex_init(data->philo_array[index].right_fork);
		
		index++;
	}
	return (data);
}
