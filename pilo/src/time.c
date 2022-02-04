/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 11:30:32 by obult         #+#    #+#                 */
/*   Updated: 2022/02/04 19:54:37 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time_in_millis(void)
{
    struct timeval	tv;

    gettimeofday(&tv,NULL);
    return (((long long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
}

long long	elapsed_time(t_philo *me)
{
	return (time_in_millis() - me->gen->start_time);
}

void	great_sleep(int	milli)
{
	long long	time;

	time = (long long)milli + time_in_millis();
	while (time  > time_in_millis())
	{
		usleep(200);
	}
}
