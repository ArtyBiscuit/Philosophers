/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:56:08 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/26 13:29:17 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	t_data data;

	init_rules(&data, 10, 15, 20);
	init_philo(&data, 5);
	philo_creat(&data);
	start_routine(&data);	
	destroy_mutex(&data);
	destroy_philo(&data, data.number_of_chair);
	free(data.philo_array);
	return (0);
}
