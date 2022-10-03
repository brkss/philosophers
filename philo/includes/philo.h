/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:22:01 by bberkass          #+#    #+#             */
/*   Updated: 2022/10/03 17:25:46 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4
# define FORK 5

typedef struct s_philo {
	pthread_t		id;
	int				nb_philos;
	int				num_eat;
	long long		last_eat;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				index;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	log;
}	t_philo;

typedef struct s_data {
	int				nb_philos;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				nb_to_eat;
	long long		start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	log;
}	t_data;

// -- utils
int			ft_atoi(const char *str);
t_data		*handle_params(int ac, char **av);

// -- routine
void		*routine(void *arg);

// -- init 
void		init_philos(t_data *data);
void		join_philos(t_data *data);
void		init_mutexes(t_data *data);
void		destroy_mutexes(t_data *data);
void		detach_philos(t_data *data);

// -- time
long long	get_time(void);
void		m_sleep(int duration, long long init);

// -- log
void		log_state(int philo_index, int action, t_philo *data);

// -- check 
int			check_num_eats(t_data *data);
void		check_philos_state(t_data *data);
#endif
