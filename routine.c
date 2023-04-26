/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:30:50 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/26 12:21:49 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <pthread.h>
#include <unistd.h>

void	*philo_routine(void *philo)
{
	t_philo *current_philo = (t_philo*)philo;
	if (current_philo->id % 2)
		usleep(500);

	exit(1);
	return (NULL);
}

