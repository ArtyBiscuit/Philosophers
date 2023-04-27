/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:50:47 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/27 18:08:08 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static int	check_str(char *str)
{
	int	index;

	index = 0;
	while(str[index])
	{
		if (!(str[index] >= '0' && str[index] <= '9'))
			return (1);
		index++;
	}
	return (0);
}

int	check_pars(int input_size, char **input)
{
	int	index;

	if (input_size != 5)
		return (1);
	index = 1;
	while (index < input_size)
	{
		if(check_str(input[index]))
			return (1);
		index++;
	}
	if (ft_atoi(input[1]) == 0)
		return (1);
	return (0);
}
