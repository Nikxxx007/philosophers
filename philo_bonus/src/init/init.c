#include "../../includes/philo.h"

void	philos_values(t_philo **philos)
{
	unsigned int i;

	i = 0;
	while (i < g_vals->philos_num)
	{
		(*philos)[i].num = i + 1;
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
	sem_unlink("forks_sem");
	if (g_vals->philos_num == 1)
	{
		g_vals->fork_sem = sem_open("forks_sem", O_CREAT | O_EXCL, 0644, 2);
		sem_wait(g_vals->fork_sem);
	}
	else
		g_vals->fork_sem = sem_open("forks_sem", O_CREAT | O_EXCL, 0644, g_vals->philos_num);
	philos = malloc(sizeof(t_philo) * g_vals->philos_num);
	if (g_vals->fork_sem == SEM_FAILED || !philos)
		return (NULL);
	philos_values(&philos);
	return (philos);
}
