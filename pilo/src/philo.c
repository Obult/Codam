/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 11:39:47 by obult         #+#    #+#                 */
/*   Updated: 2022/02/05 11:49:18 by obult         ########   odam.nl         */
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
	int		i;

	i = 0;
	me = (t_philo *)arg;
	if (me->id % 2 == 0)
		usleep(100);
	while (me->gen->eats == 0 || i < me->gen->eats)
	{
		if (ph_eat(me) == 1)
			break ;
		if (ph_sleep(me) == 1)
			break ;
		if (ph_think(me) == 1)
			break ;
		i++;
	}
	return (NULL);
}
