/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:18:21 by bberkass          #+#    #+#             */
/*   Updated: 2022/10/03 17:19:51 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		total;

	total = 0;
	gettimeofday(&time, NULL);
	total += (long long int)time.tv_sec * 1000;
	total += (long long int)time.tv_usec / 1000 ;
	return (total);
}

void	m_sleep(int duration, long long init)
{
	usleep(300);
	while (get_time() - init < (long long)duration)
		;
}
