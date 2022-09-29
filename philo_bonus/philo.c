
#include "includes/philo.h"

int main(int argc, char **argv)
{
  t_data *data;
  int i;

  if(argc == 5 || argc == 6)
  {
    data = (t_data *)malloc(sizeof(t_data));
    data = handle_params(argc, argv);
    if(!data)
    {
      printf("Error: Invalid Parameters\n");
      return (0);
    }
    sem_unlink("forks");
    data->forks = sem_open("forks", O_CREAT, 0644, data->nb_philos);
    data->pids = (pid_t *)malloc(sizeof(pid_t) * data->nb_philos);
    // create philosophers 
    i = 0;
    while(i < data->nb_philos)
    {
      data->pids[i] = fork();
      if(data->pids[i] == 0)
      {
        routine(data, i + 1); 
        exit(0);
      }
      i++;
    }
    // wait for proccesses ! 
    i = 0;
    while(i < data->nb_philos)
    {
      waitpid(data->pids[i], NULL, 0);
      i++;
    }
    sem_close(data->forks);
    free(data->pids);
    free(data);
  }
  else 
    printf("Error: Invalid Arguments!\n");

  
  return (0);
}
