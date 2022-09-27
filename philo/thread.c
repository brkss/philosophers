


#include <stdio.h>
#include <pthread.h>

void		*routine(void *arg)
{
	printf("print from thread ! : %d\n", *((int *)arg));
	for(int i = 0; i < 10000000; i++);
	*((int *)arg) += 1;
}

int main()
{
	int n;
	int i;

	i = 0;
	n = 0;
	pthread_t	thread_id[2];

	// create threads !
	while(i < 2)
	{
		pthread_create(&thread_id[i], NULL, &routine, &n);
		i++;
	}
	i = 0;
	while(i < 2)
	{
		pthread_join(thread_id[i], NULL);
		i++;
	}
	printf("after thread n = %d!\n", n);
	

	return 0;
}
