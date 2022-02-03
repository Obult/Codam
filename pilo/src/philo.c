/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 11:39:47 by obult         #+#    #+#                 */
/*   Updated: 2022/02/03 15:21:19 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*iam_philo(void *arg)
{
	t_philo	*me;

	me = (t_philo *)arg;

	printf("iam philo %i\n", me->id);
	// eat

	// sleep

	// think

	return (NULL);
}