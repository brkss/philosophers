#include "../includes/philo.h"

void *called_living(void *arg)
{
  t_th *data = (t_th *)arg;
  while(gettime() < data->last_eat + data->die)
  {
    printf("%ld %d is thinking\n", gettime(), data->id + 1);
    // -- eating
    pthread_mutex_lock(&data->forks[data->id]);
    printf("%ld %d has taken a fork\n", gettime(), data->id + 1);
    pthread_mutex_lock(&data->forks[(data->id + 1) % 5]);
    printf("%ld %d has taken a fork\n", gettime(), data->id + 1);
    printf("%ld %d is eating\n", gettime(), data->id + 1);
    usleep(data->sleep);
    data->last_eat = gettime();
    pthread_mutex_unlock(&data->forks[data->id]);
    pthread_mutex_unlock(&data->forks[(data->id + 1) % 5]);
    // -- eating
    printf("%ld %d is sleeping\n", gettime(), data->id + 1);
    usleep(data->sleep);
  }
  
  printf("%d is dead \n", data->id + 1);
  free(arg);
  return NULL;
}

t_th *init_thread_data(t_data *data, int index, pthread_mutex_t *forks)
{
  t_th *metadata;

  metadata = (t_th *)malloc(sizeof(t_th));
  metadata->die = data->die_time;
  metadata->eat = data->eat_time;
  metadata->sleep = data->sleep_time;
  metadata->id = index;
  metadata->forks = forks;
  metadata->last_eat = gettime();
  printf("last_eat : %ld\n", metadata->last_eat);
  return (metadata);
}

pthread_t *init_philos(t_data *data, t_th **threads_data)
{
  int i;
  //t_th **metadata; 
  pthread_t *philos;

  i = 0;
  philos = (pthread_t *)malloc(sizeof(pthread_t) * data->count);
  while(i < data->count)
  {
    //metadata = init_thread_data(data, i, forks);
    pthread_create(&philos[i], NULL, &called_living, threads_data[i]);
    i++;
  }
  return philos;
}

void wait_philos(pthread_t *philos, int count)
{
  int i;
 
  i = 0;
  while(i < count)
  {
    pthread_join(philos[i], NULL);
    i++;
  }
  free(philos);
}
