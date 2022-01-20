#include "philosophers.h"

void	sleep_timer(long long time_to, t_data *data)
{
	long long flag;

	flag = timestamp();
	while (!(data->dead))
	{
		if (time_diff(flag, timestamp()) >= time_to)
			break ;
		usleep(50);
	}
}

void philo_lunch(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&(data->forks[philo->left_fork]));
	print_message(data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(data->forks[philo->right_fork]));
	print_message(data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(data->is_eating));
	print_message(data, philo->id, "is eating");
	philo->death_timer = timestamp();
	pthread_mutex_unlock(&(data->is_eating));
	sleep_timer(data->time_to_eat, data);
	(philo->count_meal)++;
	pthread_mutex_unlock(&(data->forks[philo->left_fork]));
	pthread_mutex_unlock(&(data->forks[philo->right_fork]));
}

void *routine(void *philo_addr)
{
	t_philo *philo;
	t_data	*data;

	philo = (t_philo *)philo_addr;
	data = philo->data;
	if (philo->id % 2)
		usleep(15000);
	while (!(data->dead))
	{
		philo_lunch(philo, data);
		if (data->end)
			break ;
		print_message(data, philo->id, "is sleeping");
		sleep_timer(data->time_to_sleep, data);
		print_message(data, philo->id, "is thinking");
	}
	return (NULL);
}

void	death_checker(t_data *data, t_philo *philo)
{
	int	i;

	while (!(data->dead))
	{
		i = -1;
		while (++i < data->nb_philo && !(data->dead))
		{
			pthread_mutex_lock(&(data->is_eating));
			if (time_diff(philo[i].death_timer, timestamp()) > data->time_to_die)
			{
				print_message(data, i, "died");
				data->dead = 1;
			}
			pthread_mutex_unlock(&(data->is_eating));
			usleep(100);
		}
		if (data->dead)
			break ;
		i = 0;
		while (data->meal_to_eat != -1 && i < data->nb_philo && philo[i].count_meal == data->meal_to_eat)
			i++;
		if (i == data->nb_philo)
			data->end = 1;
	}
}

void	exit_resolve(t_data *data, t_philo *philo)
{
	int i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_join(philo[i].thread_id, NULL);
	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->message));
}

int resolve(t_data *data)
{
	int i;
	t_philo *philo;

	i = -1;
	philo = data->philo;
	data->init_time = timestamp();
	while (++i < data->nb_philo)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, routine, &(philo[i])))
			return (0);
		philo[i].death_timer = timestamp();
	}
	death_checker(data, data->philo);
	exit_resolve(data, data->philo);
	return (1);
}
