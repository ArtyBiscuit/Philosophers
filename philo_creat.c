/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:34:35 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/27 11:15:52 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdlib.h>

int	set_fork(t_data *data, int index_array)
{
	int		mutex_error;
	t_philo	*philo;

	mutex_error = 0;
	philo = data->philo_array;
	philo[index_array].right_fork = malloc(sizeof(pthread_mutex_t) * 1);
	mutex_error = pthread_mutex_init(philo[index_array].right_fork, NULL);
	if (!philo[index_array].right_fork || mutex_error)
	{
		destroy_philo(data, index_array);
		return (1);
	}
	if (index_array + 1 == data->number_of_chair)
		philo[0].left_fork = philo[index_array].right_fork;
	else
		philo[index_array + 1].left_fork = philo[index_array].right_fork;
	return (0);
}

int	set_mutex(t_data *data)
{
	int	mutex_error;

	mutex_error = 0;
	data->mutex = malloc(sizeof(t_mutex) * 1);
	data->mutex->say = malloc(sizeof(pthread_mutex_t) * 1);
	data->mutex->is_alive = malloc(sizeof(pthread_mutex_t) * 1);
	if (!data->mutex || !data->mutex->say || !data->mutex->is_alive)
		return (1);
	mutex_error = pthread_mutex_init(data->mutex->say, NULL);
	mutex_error = pthread_mutex_init(data->mutex->is_alive, NULL);
	if (mutex_error)
		return (1);
	return (0);
}

int	set_alive(t_data *data)
{
	int	index;
	int	*alive;

	if (data->number_of_chair)
	{
		alive = malloc(sizeof(int) * 1);
		if (!alive)
			return (1);
		*alive = 1;
		index = 0;
		while (index < data->number_of_chair)
		{
			data->philo_array[index].alive = alive;
			index++;
		}
		return (0);
	}
	return (1);
}

t_data	*philo_creat(t_data *data)
{
	int		index;
	t_philo	*philo;

	index = 0;
	philo = data->philo_array;
	if (set_mutex(data))
		return (NULL);
	if (set_alive(data))
		return (NULL);
	while (index < data->number_of_chair)
	{
		philo[index].mutex = data->mutex;
		philo[index].rules = &data->rules;
		philo[index].id = index + 1;
		if (set_fork(data, index))
		{
			write(2, "Error: set_fork.\n", 20);
			return (NULL);
		}
		index++;
	}
	return (data);
}
