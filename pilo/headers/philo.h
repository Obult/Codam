/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 14:18:48 by obult         #+#    #+#                 */
/*   Updated: 2022/01/27 17:00:29 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_general
{
    int     errornum;
    int     philocount;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     eats;
}           t_general;

int	ph_atoi(const char *nptr, int *error);

#endif