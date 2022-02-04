/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 11:39:47 by obult         #+#    #+#                 */
/*   Updated: 2022/02/04 19:11:41 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	ph_death(t_philo *me)
// {
// 	printf("%i\n", pthread_mutex_lock(&me->gen->dead.mut));
// 	return (1);
// }

void	*iam_philo(void *arg)
{
	t_philo	*me;

	me = (t_philo *)arg;
	if (me->id % 2 == 0)
		usleep(175);
	while (1)
	{
		
		// ph_death(me);
		// printf("iam philo %i\n", me->id);
		// pthread_mutex_unlock(&me->gen->dead.mut);
		if (ph_eat(me) == 1)
			break ;
		if (ph_sleep(me) == 1)
			break ;
		if (ph_think(me) == 1)
			break ;
	}
	return (NULL);
}