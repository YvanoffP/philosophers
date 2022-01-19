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
    int             fork_left;
    int             fork_right;
    int             count_meal;
    struct s_data   *data;
    pthread_mutex_t mutex;

}               t_philo;

typedef struct s_data
{
    int nb_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int meal_to_eat;
    t_philo *philo;
}               t_data;

// Errors
int str_error(char *str, int ret);
int check_arg(int argc, char **argv, t_data *data);
int arg_error(t_data *data);

// Tools
int ft_strlen(char *str);
int	ft_atoi(const char *str);

// Init
void init_data(t_data *data, char **argv);

#endif
