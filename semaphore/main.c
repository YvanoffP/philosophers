#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data		data;

	if (!check_arg(argc, argv, &data))
		return (str_error("Error arguments\n", 1));
	if (!init_sem(&data))
		return (str_error("Init semaphore failed\n", 1)); //check for free, destroy mutex etc
	if (!resolve(&data))
		return (str_error("Resolve failed\n", 1)); //check for free, destroy mutex etc
	return (0);
}
