
#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

# define EAT 1
# define SLEEP 2
# define THINK 3

typedef struct s_philo {
  pthread_t id;
  int last_eat;
  int num_eat;
  int time_to_eat;
  int time_to_sleep;
  int index;
  pthread_mutex_t *forks;
} t_philo;

typedef struct s_data {
  int nb_philos;
  int time_to_die;
  int time_to_eat;
  int time_to_sleep;
  int nb_to_eat;
  t_philo *philos;
  //pthread_t *philos;
  pthread_mutex_t *forks;
  pthread_mutex_t log;
} t_data;

// -- utils
int ft_atoi(const char *str);
t_data *handle_params(int ac, char **av);

// -- routine
void *routine(void *arg);

// -- init 
void init_philos(t_data *data);
void join_philos(t_data *data);
void init_mutexes(t_data *data);
void destroy_mutexes(t_data *data);

// -- time
unsigned int get_time();

#endif
