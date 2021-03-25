/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:42:55 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/24 11:11:17 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../utils/utils.h"
# define BUFFER_SIZE 64

typedef struct s_list
{
	char	b[BUFFER_SIZE];
	int		c;
	ssize_t	s_r;
}				t_list;

int				get_next_line(int fd, char **line);
int				end_line_pos(char *buf, int size);
void			add_to_line(char **line, char *buf, int size_util, \
		int size_line);
int				add_utils(char *buf, char **line, int *size_line, \
		int size_read);
int				end_line_parm(char *buf, int *cursor, int size_read, \
		int size_util);

#endif
