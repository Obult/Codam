/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eat_sleep_think.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 16:02:29 by obult         #+#    #+#                 */
/*   Updated: 2022/02/04 13:13:24 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ph_death(t_philo *me)
{
	printf("%i", pthread_mutex_lock(&me->gen->dead.mut));
	
}

void	ph_eat(t_philo *me)
{
	printf("%i %i is thinking");
}

void	ph_sleep(t_philo *me)
{
	printf("%i %i is thinking");
}

void	ph_think(t_philo *me)
{
	long long	timenow;

	if (ph_death(me))
	{
		timenow = 
		printf("%i %i is thinking", timenow - me->gen->start_time ,me->id);

	}
}