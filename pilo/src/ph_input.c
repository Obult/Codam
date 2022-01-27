/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ph_input.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 16:57:13 by obult         #+#    #+#                 */
/*   Updated: 2022/01/27 17:24:34 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     parse_input(t_general *data, char **argv)
{
    int error;

    error = 0;
    data->philocount = ph_atoi(argv[1], &error);
    data->time_to_die = ph_atoi(argv[2], &error);
    data->time_to_eat = ph_atoi(argv[3], &error);
    data->time_to_sleep = ph_atoi(argv[4], &error);
    data
}