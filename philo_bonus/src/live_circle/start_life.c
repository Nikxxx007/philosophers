#include "../../includes/philo.h"

void	start_eating(t_philo *philo)
{
	sem_wait(philo->vals->fork_sem);
	print_mes(philo, "has taken a fork");
	sem_wait(philo->vals->fork_sem);
	print_mes(philo, "has taken a fork");
	print_mes(philo, "is eating");
	philo->eat_timing = cur_time() - philo->vals->start;
	philo->has_eaten_c++;
	usleep(philo->vals->eat_t * 1000);
	sem_post(philo->vals->fork_sem);
	sem_post(philo->vals->fork_sem);
}

void	start_sleeping(t_philo *philo)
{
	print_mes(philo, "is sleeping");
	usleep(philo->vals->sleep_t * 1000);
}

void	*start_life(void *p_philo)
{
	t_philo *philo;
	t_vals	*vals;

	philo = (t_philo *)p_philo;
	vals = philo->vals;
//	while (g_vals->threads != g_vals->philos_num);
	philo->eat_timing = cur_time() - vals->start;
	if (philo->num % 2 == 0)
		usleep(vals->eat_t);
	while (1)
	{
		start_eating(philo);
		if (philo->has_eaten_c >= vals->food_c && vals->food_c != -1)
			break ;
		start_sleeping(philo);
		print_mes(philo, "is thinking");
	}
	return (NULL);
}
