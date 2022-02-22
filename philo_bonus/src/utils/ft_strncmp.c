/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:03:55 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/22 14:03:56 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_strncmp(const char *string1, const char *string2, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num && ((unsigned char)string1[i] != '\0'
			|| (unsigned char)string2[i] != '\0'))
	{
		if ((unsigned char)string1[i]
			!= (unsigned char)string2[i])
			return ((int)((unsigned char)string1[i]
				- (unsigned char)string2[i]));
		i++;
	}
	return (0);
}
