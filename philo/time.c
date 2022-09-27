
#include <sys/time.h>
#include <stdio.h>

int main()
{

  struct timeval current_time;
  long int converted;


  gettimeofday(&current_time, NULL);
  printf("time sc : %ld \t ms : %ld \n", current_time.tv_sec, current_time.tv_usec);
  
  return 0;
}
