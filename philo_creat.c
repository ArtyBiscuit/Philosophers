/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:34:35 by arforgea          #+#    #+#             */
/*   Updated: 2023/02/09 16:25:11 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	set_mutex(t_data *data, int index_array)
{
	t_philo *philo;

	philo = data->philo_array;
	philo[index_array].right_fork = malloc(sizeof(pthread_mutex_t) * 1);
	if (!philo[index_array].right_fork)
	{
		destroy_philo(data, index_array);
		return(1);
	}
	pthread_mutex_init(philo[index_array].right_fork, NULL);
	if (index_array + 1 == data->number_of_chair)
		philo[0].left_fork = philo[index_array].right_fork;
	else
		philo[index_array + 1].left_fork = philo[index_array].right_fork;
	return (0);
}

t_data	*philo_creat(t_data *data)
{
	int		index;
	t_philo	*philo;

	index = 0;
	philo = data->philo_array;
	while(index < data->number_of_chair)
	{
		philo[index].rules = data->rules;
		philo[index].id = index + 1;
		if(set_mutex(data, index))
		{
			write(2, "Error: set_mutex.\n", 20);
			return (NULL);
		}
		index++;
	}
	return (data);
}
