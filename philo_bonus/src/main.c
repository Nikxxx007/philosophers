/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:18:59 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/22 14:19:01 by rogaynel         ###   ########.fr       */
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
	vals->is_dead = 0;
	philos = init_philos(&vals);
	if (!philos)
	{
		cleaner(philos, &vals);
		return (0);
	}
	if (begin(philos, &vals))
		(*vals).is_dead = 1;
	cleaner(philos, &vals);
	return (0);
}
