/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogaynel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:59:33 by rogaynel          #+#    #+#             */
/*   Updated: 2022/02/22 14:59:56 by rogaynel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include <pthread.h>
# include <sys/time.h>

typedef struct s_vals
{
	unsigned int	philos_num;
	unsigned long	die_t;
	int				eat_t;
	int				sleep_t;
	int				food_c;

	unsigned long	start;
	unsigned int	threads;

	pthread_mutex_t	*fork_mux;
	pthread_mutex_t	write_mux;
}					t_vals;

typedef struct s_philo
{
	int				num;
	pthread_t		philo;
	int				has_eaten_c;
	unsigned long	eat_timing;

	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;

	t_vals			*vals;
}					t_philo;

void			er_exit(char *mes, t_vals *vals, int stuct_free);
t_vals			*parse_values(int argc, char **argv);

int				ft_atoi(const char *str, t_vals *vals);
int				ft_strncmp(const char *string1, \
		const char *string2, size_t num);

t_philo			*init_philos(t_vals **vals);
unsigned long	cur_time(void);
void			cleaner(t_philo *philos, t_vals **vals);
void			begin(t_philo *philos, t_vals **vals);
void			*start_life(void *p_philo);
void			print_mes(t_philo *philo, char *mes);

#endif //PHILO_PHILO_H
