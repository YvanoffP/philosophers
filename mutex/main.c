#include "philosophers.h"

int main(int argc, char **argv)
{
	long		nb;
	t_data		data;

	nb = 0;
	if (!check_arg(argc, argv, &data))
		return (str_error("Error arguments\n", 1));
	if (!init_mutex(&data))
		return (str_error("Init mutex failed\n", 1));	// && free /destroy mutex
	if (!resolve(&data))
		return (str_error("Resolve failed\n", 1));	// && free /destroy mutex
	return (0);
}
