

#include "../includes/philo.h"

void *routine(void *arg)
{
  t_philo *data;

  data = (t_philo *)arg;
  printf("this called from thread ! : %d\n", data->index + 1);

  return NULL;
}
