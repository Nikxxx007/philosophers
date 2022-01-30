#include "../../includes/philo.h"

void	print_mes(t_philo philo, char *mes)
{
	if (g_vals->is_dead)
		return ;
	sem_wait(g_vals->write_sem);
	printf("%ld %d %s\n", cur_time() - g_vals->start, philo.num, mes);
	sem_post(g_vals->write_sem);
}