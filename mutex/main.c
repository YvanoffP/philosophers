#include "philosophers.h"

void *routine(void *threadid)
{
   long tid;
   tid = (long)threadid;
   printf("Hello World! It's me, thread #%ld!\n", tid);
   return (0);
}

//int main(int argc, char **argv)
int main(void)
{
	pthread_t	philo[4];
	long		nb;
	int			ret;

	nb = 0;
	/*if (argc != 5)
	{
		printf("Fatal error\n");
		exit(0);
	}*/
	while (nb < 4)
	{
		printf("Creating threads ...\n");
		ret = pthread_create(&philo[nb], NULL, routine, (void *)nb);
		sleep(1);
		if (ret)
		{
			printf("Creation failed\n");
			exit(0);
		}
		nb++;
	}
	return (0);
}
