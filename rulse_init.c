/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rulse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:45:56 by arforgea          #+#    #+#             */
/*   Updated: 2023/02/09 16:29:45 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

t_data	*init_rules(t_data *data, int ttd, int tte,int tts)
{
	data->rules.time_to_die		= ttd;
	data->rules.time_to_eat		= tte;
	data->rules.time_to_sleep	= tts;
	return (data);
}
