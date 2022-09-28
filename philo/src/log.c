

#include "../includes/philo.h"


void log_state(int philo_index, int action, pthread_mutex_t log)
{
  char *state;


  if (action == SLEEP)
    state = "is sleeping";
  else if (action == EAT)
    state = "is eating";
  else if (action == THINK)
    state = "is thinking";
  else if (action == DIE)
    state = "died";
  else if (action == FORK)
    state = "has taken a fork";
  else
    return;

  pthread_mutex_lock(&log);
  printf("%lld \t %d \t %s\n", get_time(), philo_index, state);
  pthread_mutex_unlock(&log);
}
