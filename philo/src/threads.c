#include "../includes/philo.h"


void *called_living(void *arg)
{
  (void)arg;
  printf("THIS IS LIVING ! WHERE IS THAT LOUIS STORE ?\n");
  return NULL;
}

pthread_t *init_philos(t_data *data)
{
  int i;
  pthread_t *philos;

  i = 0;
  philos = (pthread_t *)malloc(sizeof(pthread_t) * data->count);
  while(i < data->count)
  {
    pthread_create(&philos[i], NULL, &called_living, &data);
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
