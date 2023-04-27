/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:12:47 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/27 18:08:34 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <pthread.h>
/*
int	check_meal(t_data *data)
{
	int index;

	index = 0;
	while(index < data->number_of_chair)
	{
		pthread_mutex_lock(&data->philo_array[index].meal_cmp);
		if (data->philo_array[index].end == 0)
		{
			pthread_mutex_unlock(&data->philo_array[index].meal_cmp);
			return (0);
		}
		pthread_mutex_unlock(&data->philo_array[index].meal_cmp);
		index++;
	}
	return (1);
}
*/
void	*supervisor_routine(void *data)
{
	t_philo *philo;
	t_data	*n_data;
	int	index;

	n_data = (t_data *)data;
	index = 0;
	while (1)
	{
		while (index < n_data->number_of_chair)
		{
			philo = &n_data->philo_array[index];
			if ((get_time() - philo->last_meal) > philo->rules->time_to_die)
			{
				p_say(philo, "Dead");
				set_dead_status(philo);
				return (NULL);
			}
			//if (check_meal(data))
			//{
			//	set_dead_status(philo);
			//	return (NULL);
			//}
			index++;
		}
		index = 0;
	}
	return (NULL);
}
