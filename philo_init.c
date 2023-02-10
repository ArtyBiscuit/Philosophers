/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:27:34 by arforgea          #+#    #+#             */
/*   Updated: 2023/02/09 16:26:25 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <pthread.h>

t_data	*init_philo(t_data *data, int number_of_chair)
{
	data->number_of_chair = number_of_chair;
	data->philo_array = malloc(sizeof(t_philo) * data->number_of_chair);
	if (!data->philo_array)
	{
		write(2, "Error: init_philo.\n", 19);
		return (NULL);
	}
	return (data);
}
