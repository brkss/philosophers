/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:15:23 by bberkass          #+#    #+#             */
/*   Updated: 2022/10/03 17:45:30 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_philos_data(t_data *data, int i)
{
	data->philos[i].log = data->log;
	data->philos[i].nb_philos = data->nb_philos;
	data->philos[i].num_eat = 0;
	data->philos[i].index = i;
	data->philos[i].time_to_eat = data->time_to_eat;
	data->philos[i].time_to_sleep = data->time_to_sleep;
	data->philos[i].last_eat = get_time();
	data->philos[i].start_time = data->start_time;
	data->philos[i].forks = data->forks;
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time();
	while (i < data->nb_philos)
	{
		init_philos_data(data, i);
		pthread_create(&data->philos[i].id, NULL, &routine, &data->philos[i]);
		i += 2;
	}
	usleep(600);
	i = 1;
	while (i < data->nb_philos)
	{
		init_philos_data(data, i);
		pthread_create(&data->philos[i].id, NULL, &routine, &data->philos[i]);
		i += 2;
	}
}

void	join_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_join(data->philos[i].id, NULL);
		i++;
	}
}

void	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->log, NULL);
	while (i < data->nb_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}
