/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 13:32:22 by obult         #+#    #+#                 */
/*   Updated: 2022/01/27 17:24:36 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     main(int argc, char **argv)
{
    t_general   data;

    if (argc < 5 || argc > 6)
        return (1);
    if (argc == 6 && argv[5][0] == '0')
        return (2);
    if (parse_input(&data, argv))
        return (3);
    
}