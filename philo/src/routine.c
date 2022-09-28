
#include "../includes/philo.h"

void *routine(void *arg)
{
  t_philo *data;

  usleep(300);
  data = (t_philo *)arg;
  while(1)
  {
    // -- eat --
    pthread_mutex_lock(&data->forks[data->index]);
    //printf("2nd fork n : %d \n", (data->index +1 ));
    log_state(data->index + 1, FORK);
    pthread_mutex_lock(&data->forks[(data->index + 1) % data->nb_philos]);
    //printf("1st fork n : %d \n", ((data->index + 1) % data->nb_philos) + 1);
    log_state(data->index + 1, FORK);

    log_state(data->index + 1, EAT);
    usleep(data->time_to_eat);
    
    pthread_mutex_unlock(&data->forks[data->index]);
    pthread_mutex_unlock(&data->forks[(data->index + 1) % data->nb_philos]);
    // -- end eat --
    log_state(data->index + 1, THINK);
    log_state(data->index + 1, SLEEP);
    usleep(data->time_to_sleep);
  }
  

  return NULL;
}
