/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:57:10 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/22 14:57:11 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
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
