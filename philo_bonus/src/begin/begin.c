#include "../../includes/philo.h"

int 	is_dead(t_philo philo)
{
	usleep(10);
	if ((cur_time() - g_vals->start - philo.eat_timing) > g_vals->die_t + 5)
	{
		g_vals->is_dead = 1;
		sem_wait(g_vals->write_sem);
		printf("%ld %d %s", cur_time() - g_vals->start, philo.num, "died\n");
		return (0);
	}
	return (1);
}

int		is_alive(t_philo *philos)
{
	unsigned int	i;
	unsigned int	philos_has_eaten;

	while (g_vals->threads != g_vals->philos_num);
	g_vals->start = cur_time();
	while (1)
	{
		i = 0;
		philos_has_eaten = 0;
		while (i < g_vals->philos_num)
		{
			if (philos[i].has_eaten_c >= g_vals->food_c && g_vals->food_c != -1)
				philos_has_eaten++;
			if (philos_has_eaten == g_vals->philos_num)
			{
				sem_wait(g_vals->write_sem);
				return (1);
			}
			else if (!(is_dead(philos[i])))
				return (0);
			i++;
		}
	}
}

int		detach_threads(t_philo *philos)
{
	unsigned int	i;
	int 			res;

	i = 0;
	while (i < g_vals->philos_num)
	{
		res = pthread_detach(philos[i].philo);
		if (res)
		{
			printf("Detach error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	begin(t_philo *philos)
{
	unsigned int	i;
	int 			res;

	i = 0;
	sem_unlink("write_sem");
	g_vals->write_sem = sem_open("write_sem", O_CREAT | O_EXCL, 0644, 1);
	while (i < g_vals->philos_num)
	{
		res = pthread_create(&philos[i].philo, NULL, start_life, (void *)(&(philos[i])));
		if (res)
		{
			printf("Thread error\n");
			detach_threads(philos);
			return ;
		}
		g_vals->threads++;
		i++;
	}
	if (!(detach_threads(philos)))
		return ;
	if (!(is_alive(philos)))
		return ;
}
