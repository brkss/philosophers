

#include "../includes/philo.h"


void log_state(int index, int action, sem_t *log)
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
  sem_wait(log);
  printf("%lld \t %d \t %s\n", get_time(), index, state);
  sem_post(log);
}
