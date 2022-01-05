#include "../../includes/philo.h"

void	print_mes(t_philo philo, char *mes)
{
	pthread_mutex_lock(&g_vals->write_mux);
	printf("%ld %d %s\n", cur_time() - g_vals->start, philo.num, mes);
	pthread_mutex_unlock(&g_vals->write_mux);
}