#include "philosophers.h"

int    ft_atoi(const char *nptr)
{
    int    sign;
    int    count;
    int    res;

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

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
