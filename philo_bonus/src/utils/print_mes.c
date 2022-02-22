/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:03:35 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/22 14:27:50 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	print_mes(t_philo *philo, char *mes)
{
	t_vals	copy;

	copy = *philo->vals;
	if (copy.is_dead)
		return ;
	sem_wait(philo->vals->write_sem);
	printf("%ld %d %s\n", cur_time() - philo->vals->start, philo->num, mes);
	sem_post(philo->vals->write_sem);
}
