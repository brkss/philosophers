
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
    log_state(data->index + 1, FORK, data->log);
    pthread_mutex_lock(&data->forks[(data->index + 1) % data->nb_philos]);
    //printf("1st fork n : %d \n", ((data->index + 1) % data->nb_philos) + 1);
    log_state(data->index + 1, FORK, data->log);

    log_state(data->index + 1, EAT, data->log);
    usleep(data->time_to_eat);
    data->last_eat = get_time();    
    pthread_mutex_unlock(&data->forks[data->index]);
    pthread_mutex_unlock(&data->forks[(data->index + 1) % data->nb_philos]);
    // -- end eat --
    log_state(data->index + 1, THINK, data->log);
    log_state(data->index + 1, SLEEP, data->log);
    usleep(data->time_to_sleep);
  }
  

  return NULL;
}
