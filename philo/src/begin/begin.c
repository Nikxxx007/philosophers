/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:56:52 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/22 14:56:54 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	is_dead(t_philo philo, t_vals **vals)
{
	usleep(10);
	if ((cur_time() - (*vals)->start - philo.eat_timing) > (*vals)->die_t + 5)
	{
		pthread_mutex_lock(&(*vals)->write_mux);
		printf("%ld %d %s", cur_time() - (*vals)->start, philo.num, "died\n");
		return (0);
	}
	return (1);
}

int	is_alive(t_philo *philos, t_vals **vals)
{
	unsigned int	i;
	unsigned int	philos_has_eaten;
	t_philo			philo;

	while ((*vals)->threads != (*vals)->philos_num)
		;
	while (1)
	{
		i = 0;
		philos_has_eaten = 0;
		while (i < (*vals)->philos_num)
		{
			philo = philos[i];
			if (philo.has_eaten_c >= (*vals)->food_c && (*vals)->food_c != -1)
				philos_has_eaten++;
			if (philos_has_eaten == (*vals)->philos_num)
			{
				pthread_mutex_lock(&((*vals)->write_mux));
				return (1);
			}
			else if (!(is_dead(philos[i], vals)))
				return (0);
			i++;
		}
	}
}

int	detach_threads(t_philo *philos, t_vals **vals)
{
	unsigned int	i;
	int				res;

	i = 0;
	while (i < (*vals)->philos_num)
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

void	begin(t_philo *philos, t_vals **vals)
{
	unsigned int	i;
	int				res;

	i = 0;
	pthread_mutex_init(&(*vals)->write_mux, NULL);
	while (i < (*vals)->philos_num)
	{
		philos[i].vals = *vals;
		res = pthread_create(&philos[i].philo, NULL, \
				start_life, (void *)(&(philos[i])));
		if (res)
		{
			printf("Thread error\n");
			detach_threads(philos, vals);
			return ;
		}
		(*vals)->threads++;
		i++;
	}
	if (!(detach_threads(philos, vals)))
		return ;
	if (!(is_alive(philos, vals)))
		return ;
}
