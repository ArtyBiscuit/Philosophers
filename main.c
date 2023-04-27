/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:56:08 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/27 18:07:31 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int argv, char **argc)
{
	t_data	data;

	if(check_pars(argv, argc))
		return (1);
	init_rules(&data, ft_atoi(argc[2]), ft_atoi(argc[3]), ft_atoi(argc[4]));
	//if (argv == 6)
	//	data.rules.number_of_meals = ft_atoi(argc[5]);
	init_philo(&data, ft_atoi(argc[1]));
	philo_creat(&data);
	start_routine(&data);
	destroy_mutex(&data);
	destroy_philo(&data, data.number_of_chair);
	free(data.philo_array);
	return (0);
}
