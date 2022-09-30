
#include "includes/philo.h"

void *watcher_routine(void *arg)
{
  t_data *data;
  int i;

  data = (t_data *)arg;
  sem_wait(data->dead);
  i = 0;
  while(i < data->nb_philos)
  {
    kill(data->pids[i], 9);
    i++;
  }
  return (NULL);
}



int main(int argc, char **argv)
{
  pthread_t watcher;
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
    pthread_create(&watcher, NULL, watcher_routine, data);    
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
    usleep(600);
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
    //waitpid(-1, NULL, 0);
    i = 0;
    while(i < data->nb_philos)
    {
      waitpid(data->pids[i], NULL, 0);
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

  
  return (0);
}
