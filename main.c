#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define  NTHREADS 3

void *Hello(void *arg)
{
	long parg = (long)arg;
	printf("The thread number %ld says: 'Hello!'\n", parg);
	pthread_exit(NULL);
}

int main(void)
{
	pthread_t threads[NTHREADS];
	long i;
	for (i=1; i <= NTHREADS; i++)
		if (pthread_create(&threads[i], NULL, Hello, (void*)i))
		{
			printf("Błąd tworzenia wątku nr %ld", i);
			abort();
		}

	for (i=1; i <= NTHREADS; i++)
		if (pthread_join(threads[i], NULL))
		{
			printf("Błąd kończenia wątku nr %ld", i);
			abort();
		}

	printf("Goodbye!\n");

	pthread_exit(NULL);
}