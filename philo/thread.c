

#include <stdio.h>
#include <pthread.h>

typedef struct data_s {
	int n;
	pthread_mutex_t n_mtx;
} data_t;

void		*routine(void *arg)
{
	data_t *data = (data_t *)arg;
	pthread_mutex_lock(&data->n_mtx);
	printf("print from thread ! : %d\n", data->n);
	for(int i = 0; i < 10000000; i++)
		data->n += 1;
	pthread_mutex_unlock(&data->n_mtx);
}

int main()
{
	data_t *data = (data_t *)malloc(sizeof(data_t));

	data->n = 0;
		
	int i;

	i = 0;
	pthread_t	thread_id[2];

	// init mutext !
	pthread_mutex_init(&data->n_mtx, NULL);

	// create threads !
	while(i < 2)
	{
		pthread_create(&thread_id[i], NULL, &routine, data);
		i++;
	}
	i = 0;
	while(i < 2)
	{
		pthread_join(thread_id[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&data->n_mtx);
	printf("after thread n = %d!\n", data->n);
	

	return 0;
}
