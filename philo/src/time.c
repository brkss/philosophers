
#include "../includes/philo.h"

unsigned int get_time()
{
  struct timeval time;
  unsigned int total;
  unsigned int converted;

  total= 0;
  gettimeofday(&time, NULL);
  converted = (unsigned int)time.tv_sec * 1000;
  total += converted;
  converted = (unsigned int)time.tv_usec / 1000;
  total += converted;

  return (total);

}
