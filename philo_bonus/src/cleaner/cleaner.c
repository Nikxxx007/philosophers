#include "../../includes/philo.h"

void	clean_forks(t_vals **vals)
{
	unsigned int	i;

	i = 0;
	if ((*vals)->philos_num == 1)
	{
		sem_post((*vals)->fork_sem);
		sem_post((*vals)->fork_sem);
		sem_unlink("forks_sem");
		sem_close((*vals)->fork_sem);
	}
	else
	{
		if ((*vals)->fork_sem)
		{
			while (i < (*vals)->philos_num)
			{
				sem_post((*vals)->fork_sem);
				i++;
			}
			sem_unlink("forks_sem");//TODO in init the same name
			sem_close((*vals)->fork_sem);
		}
	}
}

void	cleaner(t_philo *philos, t_vals **vals)
{
	if ((*vals)->fork_sem)
		clean_forks(vals);
	if (philos)
		free(philos);
	if ((*vals)->write_sem)
	{
		sem_post((*vals)->write_sem);
		sem_unlink("write_sem");
		sem_close((*vals)->write_sem);
	}
	free((*vals));
}