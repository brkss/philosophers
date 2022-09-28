
#include "includes/philo.h"

void detach_philos(t_data *data)
{
  int i;

  i = 0;
  while(i < data->nb_philos)
  {
    pthread_detach(data->philos[i].id);
    i++;
  }
}

int main(int argc, char **argv)
{
  t_data *data;
  int i;

  if(argc == 5 || argc == 6)
  {
     data = handle_params(argc, argv);
     if(!data)
     {
       printf("Error: Invalid Params\n");
       return (0);
     }
     data->philos = (t_philo *)malloc(sizeof(t_philo) * data->nb_philos);
     data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->nb_philos);
     init_mutexes(data);
     init_philos(data);
     i = 0;
     while(1)
     {
        if(i >= data->nb_philos)
          i = 0;
        if(check_num_eats(data))
        {
          detach_philos(data);
          break;
        }
        if(get_time() - data->philos[i].last_eat > data->time_to_die)
        {
          pthread_mutex_lock(&data->log);
          printf("%lld %d \t died\n", get_time(), data->philos[i].index + 1);
          detach_philos(data);
          break;
        }
        i++;
     }
     join_philos(data);
     destroy_mutexes(data);
     free(data);
  }
  else 
    printf("Error\n");

  return 0;
}

