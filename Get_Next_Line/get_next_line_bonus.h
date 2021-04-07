/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 15:36:50 by obult         #+#    #+#                 */
/*   Updated: 2020/12/17 09:50:39 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>

typedef struct	s_gnlist
{
	int					fd;
	struct s_gnlist		*next;
	char				*buff;
}				t_gnlist;

int				ft_strclen(char *s, char c);
char			*ft_addington(char *og, char *add);
int				get_next_line(int fd, char **line);
int				bufferfix(char *buff);
void			os_cpy(char *dst, char *src);

char			*lookup_fd(int fd, t_gnlist *blst);
char			*search_buff_fd(int fd, t_gnlist **blst);
void			clear_lst(t_gnlist **lst);
void			remove_fd(int fd, t_gnlist **blst);
int				get_next_lineb(int fd, char **line, char *buff);

#endif
