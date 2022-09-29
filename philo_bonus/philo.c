
#include "includes/philo.h"

int main(int argc, char **argv)
{
  t_data *data;
  int i;

  if(argc == 5 || argc == 6)
  {
    data = handle_params(argc, argv);
    if(!data)
    {
      printf("Error: Invalid Parameters\n");
      return (0);
    }
    sem_unlink("forks");
    sem_unlink("log");
    sem_unlink("dead");
    data->forks = sem_open("forks", O_CREAT, 0644, data->nb_philos);
    data->log = sem_open("log", O_CREAT, 0644, 1);
    data->dead = sem_open("dead", O_CREAT, 0644, 0);
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
      i += 2;
    }
    i = 1;
    while(i < data->nb_philos)
    {
      data->pids[i] = fork();
      if(data->pids[i] == 0)
      {
        routine(data, i + 1); 
        exit(0);
      }
      i += 2;
    }
    //wait for philosophers 
    waitpid(-1, NULL, 0);
    sem_wait(data->dead);
    i = 0;
    while(i < data->nb_philos)
    {
      kill(data->pids[i], 9);
      i++;
    }
    sem_close(data->dead);
    sem_close(data->log);
    sem_close(data->forks);
    free(data->pids);
    free(data);
  }
  else 
    printf("Error: Invalid Arguments!\n");

  while(1);
  
  return (0);
}
