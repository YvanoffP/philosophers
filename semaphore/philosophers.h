/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpauvret <tpauvret@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:22:55 by tpauvret          #+#    #+#             */
/*   Updated: 2022/01/21 15:26:27 by tpauvret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct s_philo
{
	int				id;
	int				count_meal;
	long long		death_timer;
	struct s_data	*data;
	pthread_t		death_checker;
	pid_t			process_id;
}			t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meal_to_eat;
	int				dead;
	int				end;
	long long		init_time;
	sem_t			*forks;
	sem_t			*message;
	sem_t			*is_eating;
	t_philo			philo[250];
}			t_data;

//Error
int			str_error(char *str, int ret);
int			check_arg(int argc, char **argv, t_data *data);
int			ft_strlen(char *str);

//Init
void		init_data(t_data *data, int argc, char **argv);
int			init_sem(t_data *data);
int			init_philo(t_data *data);
int			ft_atoi(const char *nptr);

//Tools
void		sleep_timer(long long time_to, t_data *data);
void		print_message(t_data *data, int id, char *str);
long long	timestamp(void);
long long	diff_time(long long flag, long long time_spent);

//Resolve
void		philo_lunch(t_philo *philo, t_data *data);
void		child_process(t_philo *philo);
void		*death_checker(void *philo_addr);
void		exit_solver(t_data *data);
int			resolve(t_data *data);

#endif
