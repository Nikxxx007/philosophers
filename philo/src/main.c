#include "../includes/philo.h"

int main(int argc, char **argv)
{
	t_philo	*philos;
	t_vals	*vals;

	if (!(argc == 5 || argc == 6))
	{
		printf("Incorrect number of values");
		return (1);
	}
	vals = parse_values(argc, argv);
	vals->start = cur_time();
	philos = init_philos(&vals);
	if (!philos)
	{
		cleaner(philos, &vals);
		return (0);
	}
	begin(philos, &vals);
	cleaner(philos, &vals);
	pthread_mutex_destroy(&vals->write_mux);
	return (0);
}
