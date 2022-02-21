#include "../../includes/philo.h"

void	init_mtxs(t_vals **vals)
{
	unsigned int i;

	i = 0;
	while (i < (*vals)->philos_num)
		pthread_mutex_init(&((*vals)->fork_mux[i++]), NULL);
	if ((*vals)->philos_num == 1)
	{
		pthread_mutex_init(&((*vals)->fork_mux[i]), NULL);
		pthread_mutex_lock(&((*vals)->fork_mux[i]));
	}
}

void	philos_values(t_philo **philos, t_vals **vals)
{
	unsigned int i;

	i = 0;
	while (i < (*vals)->philos_num)
	{
		(*philos)[i].num = i + 1;
		if (i == (*vals)->philos_num - 1)
		{
			(*philos)[i].l_fork = &((*vals)->fork_mux[0]);
			(*philos)[i].r_fork = &((*vals)->fork_mux[i]);
		}
		else
		{
			(*philos)[i].r_fork = &((*vals)->fork_mux[i]);
			(*philos)[i].l_fork = &((*vals)->fork_mux[i + 1]);
		}
		if ((*vals)->food_c != -1)
			(*philos)[i].has_eaten_c = 0;
		(*philos)[i].eat_timing = cur_time() - (*vals)->start;
		i++;
	}
}

t_philo	*init_philos(t_vals **vals)
{
	t_philo *philos;

	//malloc forks and philos structs
	if ((*vals)->philos_num == 1)
		(*vals)->fork_mux = malloc(sizeof(pthread_mutex_t) * 2);
	else
		(*vals)->fork_mux = malloc(sizeof(pthread_mutex_t) * (*vals)->philos_num);
	philos = malloc(sizeof(t_philo) * (*vals)->philos_num);
	if (!(*vals)->fork_mux || !philos)
		return (NULL);
	init_mtxs(vals);
	philos_values(&philos, vals);
	return (philos);
}
