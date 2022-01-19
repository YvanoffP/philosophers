#include "philosophers.h"

int main(int argc, char **argv)
{
	pthread_t	philo[4];
	long		nb;
	int			ret;
	t_data		data;

	nb = 0;
	if (!check_arg(argc, argv, &data))
		return (str_error("Error arguments\n", 1));
	if (!init_mutex(&data))
		return (str_error("Init mutex failed\n", 1));	// && free /destroy mutex

	//printf("Arg 1 : %d\nArg 2 : %d\nArg 3 : %d\nArg 4 : %d\nArg 5 : %d\n", data.nb_philo, data.time_to_die, data.time_to_eat, data.time_to_sleep, data.meal_to_eat);

	return (0);
}
