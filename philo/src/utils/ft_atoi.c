#include "../../includes/philo.h"

int	ft_atoi(const char *str, t_vals *vals)
{
	unsigned int	new;
	int				minus;

	new = 0;
	minus = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		minus *= -1;
	if ((*str == '-') || (*str == '+'))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		new = (new * 10) + (*str - '0');
		str++;
		if ((new > 2147483647 && minus == 1)
			|| (new > 2147483648 && minus == -1))
			er_exit("Values are out of range", vals, 1);
	}
	return ((int)(new * minus));
}