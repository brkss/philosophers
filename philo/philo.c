
#include "./includes/philo.h"

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

// count of philosophers = count of forks !
int main(int argc, char **argv)
{
  t_data *data;
  pthread_mutex_t *forks;
  pthread_t *philos;

  if(argc == 5){
    data = (t_data *)malloc(sizeof(t_data));
    data->count = ft_atoi(argv[1]);
    data->die_time = ft_atoi(argv[2]);
    data->eat_time = ft_atoi(argv[3]);
    data->sleep_time = ft_atoi(argv[4]);
    // init forks 
    forks = init_forks(data->count);
    philos = init_philos(data);
    // ----
    printf("count \t\t %d \n", data->count);
    printf("die time \t %d \n", data->die_time);
    printf("eat time \t %d \n", data->eat_time);
    printf("sleep time \t %d \n", data->sleep_time);
    wait_philos(philos, data->count);
    destroy_forks(data->count, forks);
    
    free(data);
  }
  else
    printf("Invalid Arguments ! (EXIT)\n");
  return (0);

}
