
#include "../includes/philo.h"

static int str_len(char *str)
{
  int len;

  len = 0;
  while(str[len])
    len++;
  return len;
}

static int check_no_numiric(char *str)
{
  int len;
  int i;

  if(!str) return (0);
  len = str_len(str);
  i = 0;
  while(i < len)
  {
    if(str[i] < '0' || str[i] > '9')
      return (0);
    i++;
  }
  return (1);
}

t_data *handle_params(int ac, char **av)
{
  t_data *data;
  int i;

  if(!av) return (NULL);
  i = 1;
  while(i < ac)
  {
    if(atoi(av[i]) <= 0 || !check_no_numiric(av[i]))
      return (NULL);
    i ++;
  }
  data = (t_data *)malloc(sizeof(t_data));
  if(!data) return (NULL);
  data->nb_philos = atoi(av[1]); 
  data->time_to_die = atoi(av[2]); 
  data->time_to_eat = atoi(av[3]); 
  data->time_to_sleep = atoi(av[4]); 
  if(ac == 6)
    data->nb_to_eat = atoi(av[5]);
  else
    data->nb_to_eat = -1;
  return (data);
}
