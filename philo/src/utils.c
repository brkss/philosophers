#include "../includes/philo.h"

long gettime()
{
  struct timeval t;

  gettimeofday(&t, NULL);
  return (t.tv_sec * 1000) + (long)t.tv_usec;
}
