
#include "./includes/philo.h"

// count of philosophers = count of forks !


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
    free(forks);
  }
  else
    printf("Invalid Arguments ! (EXIT)\n");
  return (0);

}
