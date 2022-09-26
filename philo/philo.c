
#include "includes/philo.h"


int main(int argc, char **argv)
{
  t_data *data;

  if(argc == 5 || argc == 6)
  {
     data = handle_params(argc, argv);
     if(!data)
     {
       printf("Error: Invalid Params\n");
       return (0);
     }
     printf("PASS\n");
  }
  else 
    printf("Error\n");

  return 0;
}

