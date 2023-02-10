/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:56:08 by arforgea          #+#    #+#             */
/*   Updated: 2023/02/09 17:08:07 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	t_data data;

	init_rules(&data, 10, 15, 20);
	init_philo(&data, 100);
	philo_creat(&data);
	for (int i = 0; i < 100; i++) {
		printf("id: %d\t| ", data.philo_array[i].id);
		printf("tte: %d | ", data.philo_array[i].rules.time_to_eat);
		printf("tts: %d | ", data.philo_array[i].rules.time_to_sleep);
		printf("ttd: %d | ", data.philo_array[i].rules.time_to_die);
		printf("%p | ", data.philo_array[i].left_fork);
		printf("%p\n", data.philo_array[i].right_fork);
	}
	start_routine(&data);
	destroy_philo(&data, data.number_of_chair);
	free(data.philo_array);
	return (0);
}
