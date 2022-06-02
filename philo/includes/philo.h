

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct s_data{
  int count;
  int die_time;
  int eat_time;
  int sleep_time;
} t_data;

int	ft_atoi(const char *str);

pthread_mutex_t *init_forks(int count);
void destroy_forks(int count, pthread_mutex_t *forks);

pthread_t *init_philos(t_data *data);
void wait_philos(pthread_t *philos, int count);

#endif
