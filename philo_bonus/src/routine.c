
#include "../includes/philo.h"

static t_philo *init(t_data *data)
{
  t_philo *philo;
  
  philo = (t_philo *)malloc(sizeof(t_philo));
  if(!philo) return (NULL);
  philo->time_to_eat = data->time_to_eat;
  philo->time_to_sleep = data->time_to_sleep;
  philo->time_to_die = data->time_to_die;
  philo->nb_to_eat = data->nb_to_eat;
  philo->last_eat = get_time();
  philo->forks = data->forks;
  philo->num_eat = 0;
  return (philo);
}

void *checker_routine(void *arg)
{
  (void)arg;
  printf("checking...\n");
  return NULL;
}

void checker(t_philo *philo)
{
  pthread_t checker_thread;

  pthread_create(&checker_thread, NULL, checker_routine, philo);
  pthread_join(checker_thread, NULL);
}

int routine(t_data *data, int index)
{
  t_philo *philo;

  philo = init(data);
  if(!philo) return (0);
  philo->index = index;
  checker(philo);
  while(1)
  {
    sem_wait(philo->forks);
    log_state(index, FORK, data->log);
    sem_wait(philo->forks);
    log_state(index, FORK, data->log);
    
    philo->last_eat = get_time();
    log_state(index, EAT, data->log);
    m_sleep(philo->time_to_eat, get_time());
    philo->num_eat += 1;
    
    sem_post(philo->forks);
    sem_post(philo->forks);
    
    log_state(index, SLEEP, data->log);
    m_sleep(philo->time_to_sleep, get_time());
    log_state(index, THINK, data->log);
  }
  return (1);
}
