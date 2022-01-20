#include "philosophers.h"

int    ft_atoi(const char *nptr)
{
    int    sign;
    int    count;
    int    res;

    sign = 1;
    count = 0;
    res = 0;
    while (nptr[count] == ' ' || (nptr[count] >= 9 && nptr[count] <= 13))
        count++;
    if (nptr[count] == '-' || nptr[count] == '+')
    {
        if (nptr[count] == '-')
            sign = sign * -1;
        count++;
    }
    while (nptr[count] >= '0' && nptr[count] <= '9')
    {
        res = res * 10 + nptr[count] - '0';
        count++;
    }
    return (res * sign);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}
