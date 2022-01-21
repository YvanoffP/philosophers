/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <tpauvret@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:23:01 by tpauvret          #+#    #+#             */
/*   Updated: 2022/01/21 23:27:27 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_lunch(t_philo *philo, t_data *data)
{
	sem_wait(data->forks);
	print_message(data, philo->id, "has taken a fork");
	sem_wait(data->forks);
	print_message(data, philo->id, "has taken a fork");
	sem_wait(data->is_eating);
	print_message(data, philo->id, "is eating");
	philo->death_timer = timestamp();
	sem_post(data->is_eating);
	sleep_timer(data->time_to_eat, data);
	(philo->count_meal)++;
	sem_post(data->forks);
	sem_post(data->forks);
}

void	child_process(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	philo->death_timer = timestamp();
	pthread_create(&(philo->death_checker), NULL, death_checker, philo);
	if (philo->id % 2)
		usleep(15000);
	while (philo->count_meal != data->meal_to_eat)
	{
		philo_lunch(philo, data);
		if (philo->count_meal == data->meal_to_eat)
			break ;
		print_message(data, philo->id, "is sleeping");
		sleep_timer(data->time_to_sleep, data);
		print_message(data, philo->id, "is thinking");
	}
	pthread_join(philo->death_checker, NULL);
	exit(0);
}

void	*death_checker(void *philo_addr)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)philo_addr;
	data = philo->data;
	while (!data->dead)
	{
		sem_wait(data->is_eating);
		if (diff_time(philo->death_timer, timestamp()) > data->time_to_die)
		{
			print_message(data, philo->id, "died");
			data->dead = 1;
			sem_wait(data->message);
			exit(1);
		}
		sem_post(data->is_eating);
		if (data->dead)
			break ;
		usleep(100);
	}
	return (NULL);
}

void	exit_solver(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		kill(data->philo[i].id, 15);
	sem_close(data->forks);
	sem_close(data->message);
	sem_close(data->is_eating);
	sem_unlink("forks");
	sem_unlink("message");
	sem_unlink("is_eating");
}

int	resolve(t_data *data)
{
	int		i;
	int		ret;
	t_philo	*philo;

	i = -1;
	philo = data->philo;
	data->init_time = timestamp();
	while (++i < data->nb_philo)
	{
		philo[i].process_id = fork();
		if (philo[i].process_id == 0)
			child_process(&philo[i]);
	}
	i = -1;
	while (++i < data->nb_philo)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
			break ;
	}
	exit_solver(data);
	return (1);
}
