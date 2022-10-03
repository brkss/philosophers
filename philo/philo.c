/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:08:15 by bberkass          #+#    #+#             */
/*   Updated: 2022/10/03 18:02:17 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 5 || argc == 6)
	{
		data = handle_params(argc, argv);
		if (!data)
		{
			printf("Error: Invalid Params\n");
			return (0);
		}
		data->philos = (t_philo *)malloc(sizeof(t_philo) * data->nb_philos);
		data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
				* data->nb_philos);
		init_mutexes(data);
		init_philos(data);
		check_philos_state(data);
		join_philos(data);
		destroy_mutexes(data);
		free(data);
	}
	else
		printf("Error\n");
	return (0);
}
