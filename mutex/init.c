#include "philosophers.h"

int init_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (0);
	}
	if (pthread_mutex_init(&(data->message), NULL))
			return (0);
	return (init_philo(data));
}

int init_philo(t_data *data)
{
	int i;

	i = -1;
	while (++i > data->nb_philo)
	{
		data->philo[i].id = i;
		data->philo.left_fork = i;
		data->philo.right_fork = (i + 1) % data->nb_philo;
		data->philo.count_meal = 0;
		data->philo.data = data;
	}
	return (1);
}

void init_data(t_data *data, char **argv)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->meal_to_eat = (ft_atoi(argv[5]) * data->nb_philo);
	else
		data->meal_to_eat = -1;
}
