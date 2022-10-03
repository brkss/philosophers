/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:16:37 by bberkass          #+#    #+#             */
/*   Updated: 2022/10/03 17:17:10 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	log_state(int philo_index, int action, t_philo *data)
{
	char	*state;

	if (action == SLEEP)
		state = "is sleeping";
	else if (action == EAT)
		state = "is eating";
	else if (action == THINK)
		state = "is thinking";
	else if (action == DIE)
		state = "died";
	else if (action == FORK)
		state = "has taken a fork";
	else
		return ;
	pthread_mutex_lock(&(data->log));
	printf("%lld \t %d \t %s\n", get_time() - data->start_time, philo_index, state);
	pthread_mutex_unlock(&(data->log));
}
