
#include "../includes/philo.h"

void *routine(void *arg)
{
  t_philo *data;

  data = (t_philo *)arg;
  while(1)
  {
    // -- eat --
    pthread_mutex_lock(&data->forks[data->index]);
    log_state(data->index + 1, FORK, data->log);
    pthread_mutex_lock(&data->forks[(data->index + 1) % data->nb_philos]);
    log_state(data->index + 1, FORK, data->log);
    log_state(data->index + 1, EAT, data->log);
    data->last_eat = get_time();    
    m_sleep(data->time_to_eat, get_time());
    data->num_eat += 1;
    pthread_mutex_unlock(&data->forks[data->index]);
    pthread_mutex_unlock(&data->forks[(data->index + 1) % data->nb_philos]);
    // -- end eat --
    log_state(data->index + 1, THINK, data->log);
    log_state(data->index + 1, SLEEP, data->log);
    m_sleep(data->time_to_sleep, get_time());
  }

  return NULL;
}
