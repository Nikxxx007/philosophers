#include "../../includes/philo.h"

void	clean_forks()
{
	unsigned int	i;

	i = 0;
	if (g_vals->philos_num == 1)
	{
		pthread_mutex_destroy(&(g_vals->fork_mux[0]));
		pthread_mutex_destroy(&(g_vals->fork_mux[1]));
	}
	else
	{
		while (i < g_vals->philos_num)
		{
			if (g_vals->fork_mux[i].__sig)
				pthread_mutex_destroy(&(g_vals->fork_mux[i]));
			i++;
		}
	}
	free(g_vals->fork_mux);
}

void	cleaner(t_philo *philos)
{
	if (g_vals->fork_mux)
		clean_forks();
	if (philos)
		free(philos);
	free(g_vals);
}