/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:10:55 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/22 14:29:08 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	clean_forks(t_vals **vals)
{
	unsigned int	i;

	i = 0;
	if ((*vals)->philos_num == 1)
	{
		sem_post((*vals)->fork_sem);
		sem_post((*vals)->fork_sem);
		sem_unlink("forks_sem");
		sem_close((*vals)->fork_sem);
	}
	else
	{
		if ((*vals)->fork_sem)
		{
			while (i < (*vals)->philos_num)
			{
				sem_post((*vals)->fork_sem);
				i++;
			}
			sem_unlink("forks_sem");
			sem_close((*vals)->fork_sem);
		}
	}
}

void	cleaner(t_philo *philos, t_vals **vals)
{
	if ((*vals)->fork_sem)
		clean_forks(vals);
	if (philos)
		free(philos);
	if ((*vals)->write_sem)
	{
		sem_post((*vals)->write_sem);
		sem_unlink("write_sem");
		sem_close((*vals)->write_sem);
	}
	free((*vals));
}
