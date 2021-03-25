/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:04:51 by etakouer          #+#    #+#             */
/*   Updated: 2021/02/21 08:45:56 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_escape(int size_read, char **line, int size_line)
{
	if (size_read == -1)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	if (size_read == 0)
	{
		(*line)[size_line] = 0;
		return (0);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static t_list	lst;
	int				e_l;
	int				s_l;
	int				u_l;

	if (fd > 255 || fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	s_l = 0;
	e_l = 0;
	*line = malloc(sizeof(char *));
	while (!e_l)
	{
		if (!(*lst.b))
		{
			lst.s_r = read(fd, lst.b, BUFFER_SIZE);
			if (lst.s_r <= 0)
				return (ft_escape(lst.s_r, line, s_l));
		}
		u_l = add_utils(lst.b + lst.c, line, &s_l, lst.s_r - lst.c);
		e_l = end_line_parm(lst.b, &(lst.c), lst.s_r, u_l);
	}
	(*line)[s_l] = 0;
	return (1);
}
