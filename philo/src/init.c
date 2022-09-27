
#include "../includes/philo.h"


void init_philos(t_data *data)
{
  int i;

  i = 0;
  while(i < data->nb_philos)
  {
    // init philos // threads 
    data->philos[i].num_eat = 0;
    data->philos[i].index = i;
    data->philos[i].last_eat = 0;
    data->philos[i].forks = data->forks;
    pthread_create(&data->philos[i].id, NULL, &routine, &data->philos[i]);
    
    i++;
  }

}

void join_philos(t_data *data)
{
  int i;

  i = 0;
  while(i < data->nb_philos)
  {
    pthread_join(data->philos[i].id, NULL);
    i++;
  }
}

void init_mutexes(t_data *data)
{
  int i;

  i = 0;
  pthread_mutex_init(&data->log, NULL);
  while(i < data->nb_philos)
  {
    pthread_mutex_init(&data->forks[i], NULL);
    i++;
  }
}


void destroy_mutexs(t_data *data)
{
  int i;

  i = 0;
  pthread_mutex_destroy(&data->log);
  while(i < data->nb_philos)
  {
    pthread_mutex_destroy(&data->forks[i]);
    i++;
  }
}
