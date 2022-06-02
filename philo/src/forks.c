
#include "../includes/philo.h"


pthread_mutex_t *init_forks(int count)
{
  int i;
  int status;
  pthread_mutex_t *forks;

  forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * count);
  i = 0;
  while(i < count)
  {
    status = pthread_mutex_init(&forks[i], NULL);
    if(status == -1)
      exit(1);
    i++;
  }
  return forks;
}

void destroy_forks(int count, pthread_mutex_t *forks)
{
  int i;
  int status;

  i = 0;
  while(i < count)
  {
    status = pthread_mutex_destroy(&forks[i]);
    if(status != 0) exit(1);
    i++;
  }
  free(forks);
}
