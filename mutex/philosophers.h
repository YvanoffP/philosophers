#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				count_meal;
	long long		death_timer;
	struct s_data	*data;
	pthread_t		thread_id;
}				t_philo;

typedef struct	s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meal_to_eat;
	int				dead;
	int				end;
	long long		init_time;
	pthread_mutex_t	forks[250]; //TODO : try to use pointer an malloc	
	pthread_mutex_t	message;
	pthread_mutex_t	is_eating;
	t_philo			philo[250]; //TODO : try to use pointer an malloc
}				t_data;

//Error
int	str_error(char *str, int ret);
int	check_arg(int argc, char **argv, t_data *data);
int	ft_strlen(char *str);

//Init
void	init_data(t_data *data, int argc, char **argv);
int		init_mutex(t_data *data);
int		init_philo(t_data *data);
int		ft_atoi(const char *nptr);

//Tools
void		sleep_timer(long long time_to, t_data *data);
void		print_message(t_data *data, int id, char *str);
long long	timestamp(void);
long long	diff_time(long long flag, long long time_spent);

//Resolve
void	philo_lunch(t_philo *philo, t_data *data);
void	*routine(void *philo_addr);
void	death_checker(t_data *data, t_philo *philo);
void	exit_solver(t_data *data, t_philo *philo);
int		resolve(t_data *data);

#endif
