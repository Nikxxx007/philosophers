/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:45:53 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/22 14:45:56 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	print_mes(t_philo *philo, char *mes)
{
	pthread_mutex_lock(&philo->vals->write_mux);
	printf("%ld %d %s\n", cur_time() - philo->vals->start, philo->num, mes);
	pthread_mutex_unlock(&philo->vals->write_mux);
}
