/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 11:30:32 by obult         #+#    #+#                 */
/*   Updated: 2022/02/04 11:50:12 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time_in_millis(void)
{
    struct timeval	tv;

    gettimeofday(&tv,NULL);
    return (((long long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
}

void	great_sleep(int	mili)
{
	long long	time;

	time = (long long)mili + time_in_millis();
	while (time  < time_in_milis())
	{
		usleep(100);
	}
}
