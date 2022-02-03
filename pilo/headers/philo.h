/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 14:18:48 by obult         #+#    #+#                 */
/*   Updated: 2022/02/03 14:56:58 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
#include <sys/time.h>

typedef struct s_philo t_philo;

typedef struct s_dead
{
	pthread_mutex_t	mut;
	int				check;
}					t_dead;

typedef struct s_general
{
	int				errornum;
	int				philocount;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eats;

	pthread_mutex_t	*forks;
	pthread_t		*philos;
	t_philo			*ph_info;
	t_dead			dead;
}					t_general;

typedef struct s_philo
{
	int			id;
	t_general	*gen;
	// time since last eaten
}				t_philo;

int	ph_atoi(const char *nptr, int *error);
int	parse_input(t_general *data, char **argv, int argc);

int	ph_initer(t_general *data);
int     parse_input(t_general *data, char **argv, int argc);
void	*start_sim(t_general *data);
void	*iam_philo(void *arg);

#endif