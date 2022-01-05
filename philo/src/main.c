#include "../includes/philo.h"

int main(int argc, char **argv)
{
	t_philo	*philos;

	if (!(argc == 5 || argc == 6))
	{
		printf("Incorrect number of values");
		return (1);
	}
	g_vals = parse_values(argc, argv);
	g_vals->start = cur_time();
	philos = init_philos();
	if (!philos)
	{
		cleaner(philos);
		return (0);//TODO add correct exit (free structk)
	}
	//TODO when simulations start init all mutexes in strct and threds
	//TODO add destroy func to free all mallocs and destroy threads and mutexes
	begin(philos);
	cleaner(philos);
	pthread_mutex_destroy(&g_vals->write_mux);
	return (0);
}
