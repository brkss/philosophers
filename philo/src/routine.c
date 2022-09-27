

#include "../includes/philo.h"

void *routine(void *arg)
{
  t_philo *data;

  data = (t_philo *)arg;


  log_state(data->index + 1, SLEEP);

  usleep(10000);

  log_state(data->index + 1, DIE);

  return NULL;
}
