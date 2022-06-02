
#include "./includes/philo.h"

// count of philosophers = count of forks !
int main(int argc, char **argv)
{
  t_data *data;
  pthread_mutex_t *forks;

  if(argc == 5){
    data = (t_data *)malloc(sizeof(t_data));
    data->count = ft_atoi(argv[1]);
    data->die_time = ft_atoi(argv[2]);
    data->eat_time = ft_atoi(argv[3]);
    data->sleep_time = ft_atoi(argv[4]);
    // init forks 
    forks = init_forks(data->count);
    // ----
    printf("count \t\t %d \n", data->count);
    printf("die time \t %d \n", data->die_time);
    printf("eat time \t %d \n", data->eat_time);
    printf("sleep time \t %d \n", data->sleep_time);
    destroy_forks(data->count, forks);
    free(data);
  }
  else
    printf("Invalid Arguments ! (EXIT)\n");
  return (0);

}
