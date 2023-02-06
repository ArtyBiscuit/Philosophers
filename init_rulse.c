/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rulse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:45:56 by arforgea          #+#    #+#             */
/*   Updated: 2023/02/06 18:38:32 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

t_data	*inti_rulse(t_data *data, int ttd, int tte,int tts)
{
	data->rules = malloc(sizeof(t_rules) * 1);
	if (!data->rules)
	{
		write(2, "Error: init_rulse.\n", 19);
		return (NULL);
	}
	data->rules->time_to_die	= ttd;
	data->rules->time_to_eat	= tte;
	data->rules->time_to_sleep	= tts;
	return (data);
}
