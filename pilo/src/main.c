/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 13:32:22 by obult         #+#    #+#                 */
/*   Updated: 2022/01/28 14:39:36 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int     main(int argc, char **argv)
{
	t_general   data;

	if (argc < 5 || argc > 6)
		return (1);
	if (argc == 6 && argv[5][0] == '0')
		return (2);
	if (parse_input(&data, argv, argc))
		return (3);
	printf("ph: %i, die: %i, eat: %i, sl: %i\n",
		data.philocount, data.time_to_die, data.time_to_eat, data.time_to_sleep);
	
}
