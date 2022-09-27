
#include "../includes/philo.h"


void init_philos(t_data *data)
{
  int i;

  i = 0;
  while(i < data->nb_philos)
  {
    // init philos // threads 
    //
    pthread_create(&data->philos[i], NULL, &routine, NULL);
    i++;
  }

}

void join_philos(t_data *data)
{
  int i;

  i = 0;
  while(i < data->nb_philos)
  {
    pthread_join(data->philos[i], NULL);
    i++;
  }
}
