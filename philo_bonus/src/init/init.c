/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:09:59 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/22 14:10:01 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	philos_values(t_philo **philos, t_vals **vals)
{
	unsigned int	i;

	i = 0;
	while (i < (*vals)->philos_num)
	{
		(*philos)[i].num = i + 1;
		if ((*vals)->food_c != -1)
			(*philos)[i].has_eaten_c = 0;
		(*philos)[i].eat_timing = cur_time() - (*vals)->start;
		i++;
	}
}

t_philo	*init_philos(t_vals **vals)
{
	t_philo	*philos;

	sem_unlink("forks_sem");
	if ((*vals)->philos_num == 1)
	{
		(*vals)->fork_sem = sem_open("forks_sem", O_CREAT | O_EXCL, 0644, 2);
		sem_wait((*vals)->fork_sem);
	}
	else
		(*vals)->fork_sem = sem_open("forks_sem", O_CREAT | O_EXCL, \
				0644, (*vals)->philos_num);
	philos = malloc(sizeof(t_philo) * (*vals)->philos_num);
	if ((*vals)->fork_sem == SEM_FAILED || !philos)
		return (NULL);
	philos_values(&philos, vals);
	return (philos);
}
