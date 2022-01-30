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
	g_vals->is_dead = 0;
	philos = init_philos();
	if (!philos)
	{
		cleaner(philos);
		return (0);
	}
	begin(philos);
	cleaner(philos);
	return (0);
}
