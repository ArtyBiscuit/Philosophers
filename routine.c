/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:30:50 by arforgea          #+#    #+#             */
/*   Updated: 2023/02/10 17:08:15 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <unistd.h>

void	*philo_routine(void *philo)
{
	t_philo *current_philo = (t_philo*)philo;
	if (current_philo->id % 2)
		usleep(500);

	return (NULL);
}

