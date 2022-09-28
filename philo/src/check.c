

#include "../includes/philo.h"


int check_num_eats(t_data *data)
{
  int i;

  if(data->nb_to_eat == -1)
    return (0);

  i = 0;
  while(i < data->nb_philos)
  {
    if(data->philos[i].num_eat < data->nb_to_eat)
      return (0);
    i++;
  }

  return (1);
}
