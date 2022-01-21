/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <tpauvret@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:22:34 by tpauvret          #+#    #+#             */
/*   Updated: 2022/01/21 15:22:38 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_data(t_data *data, int argc, char **argv)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->dead = 0;
	data->end = 0;
	if (argc == 6)
		data->meal_to_eat = ft_atoi(argv[5]);
	else
		data->meal_to_eat = -1;
}

int	init_sem(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("message");
	sem_unlink("is_eating");
	data->forks = sem_open("forks", O_CREAT, S_IRWXU, data->nb_philo);
	data->message = sem_open("message", O_CREAT, S_IRWXU, 1);
	data->is_eating = sem_open("is_eating", O_CREAT, S_IRWXU, 1);
	if (data->forks <= 0 || data->message <= 0 || data->is_eating <= 0)
		return (0);
	return (init_philo(data));
}

int	init_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		data->philo[i].id = i;
		data->philo[i].count_meal = 0;
		data->philo[i].death_timer = 0;
		data->philo[i].data = data;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	count;
	int	res;

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
