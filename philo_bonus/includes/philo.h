

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/time.h>

typedef struct s_data {
  sem_t *forks;
  int nb_philos;
  long long time_to_die;
  long long time_to_eat;
  long long time_to_sleep;
  int nb_to_eat;
  pid_t *pids;
  
} t_data;

// -- utils 
int ft_atoi(const char *str);
t_data *handle_params(int ac, char **av);

// -- time
long long get_time();
void m_sleep(int duration, long long init);

#endif
