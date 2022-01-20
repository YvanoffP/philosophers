#include "philosophers.h"

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long diff_time(long long flag, long long time_spent)
{
	return (time_spent - flag);
}

void	sleep_timer(long long time_to, t_data *data)
{
	long long	flag;

	flag = timestamp();
	while (!(data->dead))
	{
		if (diff_time(flag, timestamp()) >= time_to)
			break ;
		usleep(50);
	}
}

void	print_message(t_data *data, int id, char *str)
{
	pthread_mutex_lock(&(data->message));
	if (!(data->dead))
	{
		printf("%lli ", timestamp() - data->init_time);
		printf("%i ", id + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(data->message));
	return ;
}
