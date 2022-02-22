/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:06:08 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/22 14:28:52 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	is_valid(int argc, char **argv)
{
	int	i;
	int	j;
	int	check;

	check = 0;
	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		if (!(ft_strncmp(argv[i], "0", 1)) && i != 5)
			return (0);
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				check = 1;
			j++;
		}
		if (check || !(ft_strncmp(argv[i], "", 1)))
			return (0);
		i++;
	}
	return (1);
}

t_vals	*parse_values(int argc, char **argv)
{
	t_vals	*vals;

	vals = (t_vals *)malloc(sizeof(t_vals));
	if (!vals)
		exit(0);
	if (!(is_valid(argc, argv)))
		er_exit("Incorrect values", vals, 1);
	vals->philos_num = ft_atoi(argv[1], vals);
	vals->die_t = ft_atoi(argv[2], vals);
	vals->eat_t = ft_atoi(argv[3], vals);
	vals->sleep_t = ft_atoi(argv[4], vals);
	if (argc > 5)
	{
		if (!(ft_strncmp(argv[5], "0", 1)))
		{
			free(vals);
			exit(0);
		}
		vals->food_c = ft_atoi(argv[5], vals);
	}
	else
		vals->food_c = -1;
	return (vals);
}
