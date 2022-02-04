/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_sim.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 16:41:10 by obult         #+#    #+#                 */
/*   Updated: 2022/02/04 19:23:06 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_sim(t_general *data)
{
	int	i;

	i = 0;
	data->dead.check = 0;
	data->start_time = time_in_millis();
	pthread_mutex_init(&data->dead.mut, NULL);
	int j = data->philocount;
	while (j)
	{
		j--;
		pthread_mutex_init(&data->forks[j], NULL);
	}
	while (i < data->philocount)
	{
		data->ph_info[i].last_eaten = data->start_time;
// 
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
	pthread_mutex_destroy(&data->dead.mut);
	return (NULL);
}