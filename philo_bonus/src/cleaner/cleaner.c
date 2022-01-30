#include "../../includes/philo.h"

void	clean_forks()
{
	unsigned int	i;

	i = 0;
	if (g_vals->philos_num == 1)
	{
		sem_post(g_vals->fork_sem);
		sem_post(g_vals->fork_sem);
		sem_unlink("forks_sem");
		sem_close(g_vals->fork_sem);
	}
	else
	{
		if (g_vals->fork_sem)
		{
			while (i < g_vals->philos_num)
			{
				sem_post(g_vals->fork_sem);
				i++;
			}
			sem_unlink("forks_sem");//TODO in init the same name
			sem_close(g_vals->fork_sem);
		}
	}
}

void	cleaner(t_philo *philos)
{
	if (g_vals->fork_sem)
		clean_forks();
	if (philos)
		free(philos);
	if (g_vals->write_sem)
	{
		sem_post(g_vals->write_sem);
		sem_unlink("write_sem");
		sem_close(g_vals->write_sem);
	}
	free(g_vals);
}