

#include "includes/philo.h"

# define NUM 4 

int main()
{
  pid_t pid[NUM];
  sem_t *sem;
  int i;

  sem = sem_open("fork", O_CREAT, 0644, NUM);
  
  i = 0;
  while(i < NUM)
  {
    pid[i] = fork();
    if(pid[i] == 0)
    {
      sem_wait(sem);
      sleep(1);
      printf("this printed from the sup process\n");
      sem_post(sem);
      exit(0);
    }
    i++;
  }

  i = 0;
  while(i < NUM)
  {
    waitpid(pid[i], NULL,0);
    i++;
  }

  return (0);
}
