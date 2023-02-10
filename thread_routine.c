/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:30:50 by arforgea          #+#    #+#             */
/*   Updated: 2023/02/09 17:14:28 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	*thread_routine(void *philo)
{
	t_philo *current_philo;

	current_philo = (t_philo*)philo;
	//if (current_philo->id % 2)
	//	usleep(500);
	usleep(current_philo->id * 1000);
	printf("ID: %d, Say Hello !\n", current_philo->id);
	return (NULL);
}

