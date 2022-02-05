/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_sim.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 16:41:10 by obult         #+#    #+#                 */
/*   Updated: 2022/02/05 16:54:29 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	someonedied_function(t_general *data, int philo)
{
	int	i;

	i = 0;
	while (i < (data->philocount + 9) / 10)
	{
		pthread_mutex_lock(&data->dead[i].mut);
		data->dead[i].check = 1;
	}
	printf("time: %i, philo: %i dieded\n", (int)elapsed_time(&data->ph_info[philo]), philo);
	i = 0;
	while (i < (data->philocount + 9) / 10)
	{
		pthread_mutex_unlock(&data->dead[i].mut);
	}
}

void	ph_holy_thread(t_general *data)
{
	int	i;
	int c;

	c = 0;
	while (1)
	{
		i = 0;
		while (i < data->philocount)
		{
			if (time_in_millis() > data->ph_info[i].last_eaten + data->time_to_die)
			{
				printf("dead philo alert! (%i)(%lld)\n", i + 1, elapsed_time(data->ph_info));
				c = 1;
				break ;
			}
			pthread_mutex_lock(&data->dead[i / 10].mut);
			if (data->dead[i / 10].check != 0)
			{

				someonedied_function(data, data->dead[i / 10].check);
				c = 1;
				break ;
			}
			else
				pthread_mutex_unlock(&data->dead[i / 10].mut);
			i++;
		}
		if (c)
			break ;
	}
}

void	*start_sim(t_general *data)
{
	int	i;

	i = 0;
	
	data->start_time = time_in_millis();
	int k = 0;
	while (k < (data->philocount + 9) / 10)
	{
		data->dead[k].check = 0;
		pthread_mutex_init(&data->dead[k].mut, NULL);
		k++;
	}
	int j = data->philocount;
	while (j)
	{
		j--;
		pthread_mutex_init(&data->forks[j], NULL);
	}
	while (i < data->philocount)
	{
		data->ph_info[i].last_eaten = data->start_time;
		pthread_create(&data->philos[i], NULL, iam_philo, (void *)&data->ph_info[i]);
		i++;
	}
	ph_holy_thread(data);
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
	// pthread_mutex_destroy(&data->dead.mut); needs to be whole array
	return (NULL);
}