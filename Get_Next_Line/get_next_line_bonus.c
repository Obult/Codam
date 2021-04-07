/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/09 15:49:41 by oswin         #+#    #+#                 */
/*   Updated: 2020/12/17 09:43:42 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	static t_gnlist		*buff;
	int					ret;

	if (fd == 1)
	{
		clear_lst(&buff);
		return (0);
	}
	if (!line || fd < 0 || BUFFER_SIZE == 0)
		return (-1);
	if (!search_buff_fd(fd, &buff))
		return (-1);
	ret = get_next_lineb(fd, line, search_buff_fd(fd, &buff));
	if (!ret)
		remove_fd(fd, &buff);
	return (ret);
}

void	remove_fd(int fd, t_gnlist **blst)
{
	t_gnlist	*cur;
	t_gnlist	*pre;

	pre = *blst;
	if (pre->fd == fd)
	{
		*blst = pre->next;
		free(pre->buff);
		free(pre);
		return ;
	}
	cur = pre->next;
	while (cur)
	{
		if (cur->fd == fd)
		{
			pre->next = cur->next;
			free(cur->buff);
			free(cur);
			return ;
		}
		cur = cur->next;
		pre = pre->next;
	}
}

void	clear_lst(t_gnlist **lst)
{
	t_gnlist	*clear;

	while (*lst)
	{
		clear = *lst;
		*lst = clear->next;
		free(clear->buff);
		free(clear);
	}
}

char	*search_buff_fd(int fd, t_gnlist **blst)
{
	t_gnlist	*tmp;
	int			i;

	i = 0;
	if (lookup_fd(fd, *blst))
		return (lookup_fd(fd, *blst));
	tmp = malloc(sizeof(t_gnlist));
	if (!tmp)
		return (0);
	tmp->fd = fd;
	tmp->next = *blst;
	tmp->buff = malloc(BUFFER_SIZE + 1);
	if (!tmp->buff)
	{
		free(tmp);
		return (0);
	}
	while (i < BUFFER_SIZE)
	{
		tmp->buff[i] = 0;
		i++;
	}
	*blst = tmp;
	return (tmp->buff);
}

char	*lookup_fd(int fd, t_gnlist *blst)
{
	while (blst)
	{
		if (blst->fd == fd)
			return (blst->buff);
		blst = blst->next;
	}
	return (0);
}
