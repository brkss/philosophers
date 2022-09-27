

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_philo {
  int last_eat;
  int num_eat;
  pthread_mutex_t *forks;
  int index;
} t_philo;

typedef struct s_data {
  int nb_philos;
  int time_to_die;
  int time_to_eat;
  int time_to_sleep;
  int nb_to_eat;
  pthread_t *philos;
  pthread_mutex_t *forks;
  pthread_mutex_t log;
} t_data;

// -- functions signature
int ft_atoi(const char *str);
t_data *handle_params(int ac, char **av);

void *routine(void *arg);
void init_philos(t_data *data);
void join_philos(t_data *data);

#endif
