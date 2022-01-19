/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 12:52:23 by obult         #+#    #+#                 */
/*   Updated: 2022/01/19 15:36:56 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// # include <pthread.h>
// # include <stdio.h>
// # include <stdlib.h>
// #include <unistd.h>

void	*start_routine(void *i)
{
	int num;
	
	num = *(int *)i;
	printf("%i\n", num);
	return (NULL);
}

int	main(void)
{
	pthread_mutex_t	*mutex;
	int	i;
	pthread_t arr[4];
	int	num[4];

	num[0] = 0;
	num[1] = 1;
	num[2] = 2;
	num[3] = 3;
	i = 0;

	pthread_mutex_init(mutex, NULL);


	while (i < 4)
	{
		pthread_create(&arr[i], NULL, start_routine, (void *)(&num[i]));
		i++;
	}
	while (i)
	{
		i--;
		pthread_join(arr[i], NULL);
	}
	pthread_mutex_destroy(mutex);
}