
#include "../includes/philo.h"

long long get_time()
{
  struct timeval time;
  long long total;

  total = 0;
  gettimeofday(&time, NULL);
  total += (long long int)time.tv_sec * 1000;
  total += (long long int)time.tv_usec / 1000 ;

  return (total);
}

void m_sleep(int duration, long long init)
{
  usleep(300);
  while(get_time() - init < (long long)duration);
}
