

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_data {
  int nb_philos;
  int time_to_die;
  int time_to_eat;
  int time_to_sleep;
  int nb_to_eat;
} t_data;

// -- functions signature
int ft_atoi(const char *str);
t_data *handle_params(int ac, char **av);




#endif
