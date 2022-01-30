#include "../../includes/philo.h"

void	start_eating(t_philo *philo)
{
	sem_wait(g_vals->fork_sem);
	print_mes(*philo, "has taken a fork");
	sem_wait(g_vals->fork_sem);
	print_mes(*philo, "has taken a fork");
	print_mes(*philo, "is eating");
	philo->eat_timing = cur_time() - g_vals->start;
	philo->has_eaten_c++;
	usleep(g_vals->eat_t * 1000);
	sem_post(g_vals->fork_sem);
	sem_post(g_vals->fork_sem);
}

void	start_sleeping(t_philo *philo)
{
	print_mes(*philo, "is sleeping");
	usleep(g_vals->sleep_t * 1000);
}

void	*start_life(void *p_philo)
{
	t_philo *philo;

	philo = (t_philo *)p_philo;
	while (g_vals->threads != g_vals->philos_num);
	philo->eat_timing = cur_time() - g_vals->start;
	if (philo->num % 2 == 0)
		usleep(g_vals->eat_t);
	while (1)
	{
		start_eating(philo);
		if (philo->has_eaten_c >= g_vals->food_c && g_vals->food_c != -1)
			break ;
		start_sleeping(philo);
		print_mes(*philo, "is thinking");
	}
	return (NULL);
}
