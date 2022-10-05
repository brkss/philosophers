/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:13:03 by bberkass          #+#    #+#             */
/*   Updated: 2022/10/03 19:04:05 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_num_eats(t_data *data)
{
	int	i;

	if (data->nb_to_eat == -1)
		return (0);
	i = 0;
	while (i < data->nb_philos)
	{
		if (data->philos[i].num_eat < data->nb_to_eat)
			return (0);
		i++;
	}
	return (1);
}

void	check_philos_state(t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i >= data->nb_philos)
			i = 0;
		if (check_num_eats(data))
		{
			detach_philos(data);
			break ;
		}
		if (get_time() - data->philos[i].last_eat > data->time_to_die)
		{
			pthread_mutex_lock(&data->log);
			printf("%lld \t %d \t died\n", get_time() - data->start_time,
				data->philos[i].index + 1);
			detach_philos(data);
			break ;
		}
		i++;
	  usleep(100);
  }
}
