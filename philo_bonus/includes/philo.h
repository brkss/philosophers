
#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/time.h>
#include <pthread.h>
#include <signal.h>

# define EAT 1
# define SLEEP 2 
# define THINK 3
# define DIE 4
# define FORK 5

typedef struct s_data {
  sem_t *forks;
  int nb_philos;
  long long time_to_die;
  long long time_to_eat;
  long long time_to_sleep;
  int nb_to_eat;
  pid_t *pids;
  sem_t *log;
} t_data;

typedef struct s_philo
{
  int index;
  int nb_to_eat;
  int num_eat;
  long long time_to_die;
  long long time_to_eat;
  long long time_to_sleep;
  long long last_eat;
  sem_t *forks;
  sem_t *log;
} t_philo;

// -- utils 
int ft_atoi(const char *str);
t_data *handle_params(int ac, char **av);

// -- routine 
int routine(t_data *data, int index);

// -- time
long long get_time();
void m_sleep(int duration, long long init);

// -- log
void log_state(int index, int action, sem_t *log);

#endif
