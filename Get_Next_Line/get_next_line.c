/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 16:08:40 by oswin         #+#    #+#                 */
/*   Updated: 2020/12/17 09:44:18 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		buff[BUFFER_SIZE + 1];

	if (!line)
		return (-1);
	return (get_next_lineb(fd, line, buff));
}
