

#include "../includes/philo.h"



t_th **create_thread_data(t_data *data, pthread_mutex_t *forks)
{
  int i;
  t_th **metadata;
  
  metadata = (t_th**)malloc(sizeof(t_th *) * data->count);
  i = 0;
  while(i < data->count)
  {
    metadata[i] = init_thread_data(data, i, forks);
    i++;
  }
  return (metadata);
}
