#include "../../includes/philo.h"

void	init_mtxs(void)
{
	int i;

	i = 0;
	while (i < g_vals->philos_num)
		pthread_mutex_init(&(g_vals->fork_mux[i++]), NULL);
	if (g_vals->philos_num == 1)
	{
		pthread_mutex_init(&(g_vals->fork_mux[i]), NULL);
		pthread_mutex_lock(&(g_vals->fork_mux[i]));
	}
}

void	philos_values(t_philo **philos)
{
	int i;

	i = 0;
	while (i < g_vals->philos_num)
	{
		(*philos)[i].num = i + 1;
		if (i == g_vals->philos_num - 1)
		{
			(*philos)[i].l_fork = &(g_vals->fork_mux[0]);
			(*philos)[i].r_fork = &(g_vals->fork_mux[i]);
		}
		else
		{
			(*philos)[i].l_fork = &(g_vals->fork_mux[i]);
			(*philos)[i].r_fork = &(g_vals->fork_mux[i + 1]);
		}
		if (g_vals->food_c != -1)
			(*philos)[i].has_eaten_c = 0;
		(*philos)[i].eat_timing = cur_time() - g_vals->start;
		i++;
	}
}

t_philo	*init_philos(void)
{
	t_philo *philos;

	//malloc forks and philos structs
	if (g_vals->philos_num == 1)
		g_vals->fork_mux = malloc(sizeof(pthread_mutex_t) * 2);
	else
		g_vals->fork_mux = malloc(sizeof(pthread_mutex_t) * g_vals->philos_num);
	philos = malloc(sizeof(t_philo) * g_vals->philos_num);
	if (!g_vals->fork_mux || !philos)
		return (NULL);
	init_mtxs(); //write mutex isn't yet inited
	philos_values(&philos);
	return (philos);
}
