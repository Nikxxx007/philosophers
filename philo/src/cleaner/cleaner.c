#include "../../includes/philo.h"

void	clean_forks(t_vals **vals)
{
	unsigned int	i;

	i = 0;
	if ((*vals)->philos_num == 1)
	{
		pthread_mutex_destroy(&((*vals)->fork_mux[0]));
		pthread_mutex_destroy(&((*vals)->fork_mux[1]));
	}
	else
	{
		while (i < (*vals)->philos_num)
		{
			if ((*vals)->fork_mux[i].__sig)
				pthread_mutex_destroy(&((*vals)->fork_mux[i]));
			i++;
		}
	}
	free((*vals)->fork_mux);
}

void	cleaner(t_philo *philos, t_vals **vals)
{
	if ((*vals)->fork_mux)
		clean_forks(vals);
	if (philos)
		free(philos);
	free(*vals);
}