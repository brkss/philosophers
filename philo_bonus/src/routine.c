
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
  philo->log = data->log;
  philo->dead = data->dead;
  return (philo);
}

void *checker_routine(void *arg)
{
  t_philo *philo;

  m_sleep(100, get_time());
  philo = (t_philo *)arg;
  while(1)
  {
    if(get_time() - philo->last_eat > philo->time_to_die)
    {
      sem_wait(philo->log);
      printf("%lld \t %d \t died\n", get_time(), philo->index);
      sem_post(philo->dead);
      free(philo);
      exit(33);
    }
  }
  return NULL;
}

pthread_t *checker(t_philo *philo)
{
  pthread_t *checker_thread;

  checker_thread = (pthread_t *)malloc(sizeof(pthread_t));
  pthread_create(checker_thread, NULL, checker_routine, philo);
  return (checker_thread);
}

int routine(t_data *data, int index)
{
  t_philo *philo;
  pthread_t *checker_thread;

  philo = init(data);
  
  if(!philo) return (0);
  philo->index = index;
  checker_thread = checker(philo);
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
  pthread_join(*checker_thread, NULL);
  return (1);
}
