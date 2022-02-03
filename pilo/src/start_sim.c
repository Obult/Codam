/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_sim.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 16:41:10 by obult         #+#    #+#                 */
/*   Updated: 2022/02/03 14:58:05 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_sim(t_general *data)
{
	int	i;

	i = 0;
	while (i < data->philocount)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_create(&data->philos[i], NULL, iam_philo, (void *)&data->ph_info[i]);
		i++;
	}
	while (i)
	{
		i--;
		pthread_join(data->philos[i], NULL);
	}
	while (i < data->philocount)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}

	return (NULL);
}