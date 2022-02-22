/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   er_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:11:10 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/22 14:11:11 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	er_exit(char *mes, t_vals *vals, int stuct_free)
{
	if (stuct_free)
		free(vals);
	printf("Error: %s", mes);
	exit(2);
}
