/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ph_input.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 16:57:13 by obult         #+#    #+#                 */
/*   Updated: 2022/01/28 14:40:24 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     parse_input(t_general *data, char **argv, int argc)
{
    int error;

    error = 0;
    data->philocount = ph_atoi(argv[1], &error);
    data->time_to_die = ph_atoi(argv[2], &error);
    data->time_to_eat = ph_atoi(argv[3], &error);
    data->time_to_sleep = ph_atoi(argv[4], &error);
    if (argc == 6)
        data->eats = ph_atoi(argv[5], &error);
    if (data->philocount < 0 || data->time_to_die < 0 || data->time_to_eat < 0
        || data->time_to_sleep < 0)
        return (1);
    if (argc == 6 && data->eats < 0)
        return (1);
    return (error);
}
