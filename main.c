/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:56:08 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/27 11:17:10 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(void)
{
	t_data	data;

	init_rules(&data, 410, 200, 200);
	init_philo(&data, 200);
	philo_creat(&data);
	start_routine(&data);
	destroy_mutex(&data);
	destroy_philo(&data, data.number_of_chair);
	free(data.philo_array);
	return (0);
}
