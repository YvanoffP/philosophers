#include "philosophers.h"

int str_error(char *str, int ret)
{
	write(1, str, ft_strlen(str));
	return (ret);
}

int check_arg(int argc, char **argv, t_data *data)
{
	if (argc != 6)
		return (0);
	init_data(data, argv);
	return (1);
}
