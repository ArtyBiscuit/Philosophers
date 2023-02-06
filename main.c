/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:56:08 by arforgea          #+#    #+#             */
/*   Updated: 2023/02/06 17:43:42 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

#include <stdio.h>






typedef struct	s_data
{
	pthread_mutex_t mutex;
	int a;
	int b;
}				t_data;

void	*calc(void* arg)
{
	t_data *data = (t_data*)arg;
	pthread_mutex_lock(&data->mutex);
	data->a = data->a + data->b;
	data->b = data->a;
	printf("%d\n", data->a);
	pthread_mutex_unlock(&data->mutex);
	return (NULL);
}

int main(void)
{
	pthread_t t[100];
	t_data *data;
	data = malloc(sizeof(t_data) * 1);
	data->a = 1;
	data->b = 1;

	int index = 0;
	while (index != 100)
	{
		pthread_create(&t[index], NULL, &calc, data);
		index++;
	}
	index = 0;
	while (index != 100)
	{
		pthread_join(t[index], NULL);
		index++;
	}
	free(data);
}
