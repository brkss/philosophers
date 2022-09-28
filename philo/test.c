

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>


int main()
{
  struct timeval ct;

  int i = 0;

  while(i < 10)
  {
    printf("-------------\n");
    gettimeofday(&ct, NULL);
    printf("a usec : %d", ct.tv_usec);
    usleep(1000);
    gettimeofday(&ct, NULL);
    printf("b usec : %d", ct.tv_usec);
    printf("-------------\n");
    i++;
  }

  
  return(0);
}
