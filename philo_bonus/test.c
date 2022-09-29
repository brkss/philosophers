

#include "includes/philo.h"

# define NUM 4 

int main()
{
  pid_t pid[NUM];
  sem_t *sem;
  int i;

  sem_unlink("forks"); // unlink semaphores with the same name 
  sem = sem_open("forks", O_CREAT, 0644, 1);
  
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
  //sem_close(sem);
  return (0);
}
