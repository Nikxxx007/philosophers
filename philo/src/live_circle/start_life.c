/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:51:46 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/22 14:51:48 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	start_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_mes(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	print_mes(philo, "has taken a fork");
	print_mes(philo, "is eating");
	philo->eat_timing = cur_time() - philo->vals->start;
	philo->has_eaten_c++;
	usleep(philo->vals->eat_t * 1000);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	start_sleeping(t_philo *philo)
{
	print_mes(philo, "is sleeping");
	usleep(philo->vals->sleep_t * 1000);
}

void	*start_life(void *p_philo)
{
	t_philo	*philo;
	t_vals	*vals;

	philo = (t_philo *)p_philo;
	vals = philo->vals;
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
