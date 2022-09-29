
#include "includes/philo.h"

int main(int argc, char **argv)
{
  t_data *data;
  
  if(argc == 5 || argc == 6)
  {
    data = (t_data *)malloc(sizeof(t_data));
    data = handle_params(argc, argv);
    if(!data)
    {
      printf("Error: Invalid Parameters\n");
      return (0);
    }
    printf("nb philos : %d\n", data->nb_philos);
    printf("time to eat %lld\n", data->time_to_eat);
    printf("time to die %lld\n", data->time_to_die);
    printf("time to sleep %lld\n", data->time_to_sleep);
    printf("nb to eat : %d\n", data->nb_to_eat);
  }
  else 
    printf("Error: Invalid Arguments!\n");

  return (0);
}
