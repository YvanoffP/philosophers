#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_philo
{
    int             id;
    int             left_fork;
    int             right_fork;
    int             count_meal;
    long long       death_timer;
    struct s_data   *data;
    pthread_t       thread_id;
}               t_philo;

typedef struct s_data
{
    int             nb_philo;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             meal_to_eat;
    int             dead;
    int             end;
    long long       init_time;
    pthread_mutex_t is_eating;
    pthread_mutex_t forks[250]; //TODO : make it better bro.
    pthread_mutex_t message;
    t_philo         philo[250];
}               t_data;

// Errors
int         str_error(char *str, int ret);
int         check_arg(int argc, char **argv, t_data *data);
int         arg_error(t_data *data);

// Tools
int         ft_strlen(char *str);
int	        ft_atoi(const char *str);
long long   timestamp(void);
long long   time_diff(long long past, long long pres);
void        print_message(t_data *data, int id, char *str);

// Init
void        init_data(t_data *data, char **argv);
int         init_mutex(t_data *data);
int         init_philo(t_data *data);

// Resolve
void        sleep_timer(long long time_to, t_data *data);
void        philo_lunch(t_philo *philo, t_data *data);
void        *routine(void *philo_addr);
int         resolve(t_data *data);
void        exit_resolve(t_data *data, t_philo *philo);

#endif
