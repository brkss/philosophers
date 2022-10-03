

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

  int status = -42;

  status = waitpid(-1, NULL, 0);
  printf("wait pid status : %d\n", status);

  return (0);

}
