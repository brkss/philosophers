
#include "includes/philo.h"


int main(int argc, char **argv)
{
  t_data *data;
  

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
     init_philos(data);
     join_philos(data);
     printf("PASS\n");
     free(data);
  }
  else 
    printf("Error\n");

  return 0;
}

