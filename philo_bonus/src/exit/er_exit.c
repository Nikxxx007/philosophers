#include "../../includes/philo.h"

void	er_exit(char *mes, t_vals *vals, int stuct_free)
{
	if (stuct_free)
		free(vals);
	printf("Error: %s", mes);
	exit(2);
}
