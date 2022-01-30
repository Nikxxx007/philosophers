#include "../../includes/philo.h"

unsigned long	cur_time()
{
	struct timeval cur_time;

	gettimeofday(&cur_time, NULL);
	return ((cur_time.tv_sec) * 1000 + (cur_time.tv_usec) / 1000);
}