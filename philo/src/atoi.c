/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:12:09 by bberkass          #+#    #+#             */
/*   Updated: 2022/10/03 17:12:13 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_isdigit(int d)
{
	if (d >= '0' && d <= '9')
		return (1);
	return (0);
}

static void	ft_checksign(const char *str, int *negative, unsigned int *index)
{
	if (str[*index] == '-' || str[*index] == '+')
	{
		if (str[*index] == '-')
			*negative = 1;
		*index = *index + 1;
	}
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				negative;
	int				mul;
	int				total;

  negative = 0;
	i = 0;
	mul = 1;
	total = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	ft_checksign(str, &negative, &i);
	while (str[i] && ft_isdigit(str[i]))
	{
		total = total * 10 + (str[i] - 48);
		i++;
	}
	if (negative)
		return (total * -1);
	return (total);
}
