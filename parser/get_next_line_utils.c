/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 07:33:37 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/24 11:08:08 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	end_line_pos(char *buf, int size)
{
	int	i;

	i = 0;
	while (i < size && buf[i] != '\n')
		i++;
	return (i);
}

void	add_to_line(char **line, char *buf, int size_util, int size_line)
{
	char	*new_line;

	new_line = malloc(sizeof(char) * size_line + size_util + 1);
	ft_memcpy(new_line, *line, size_line);
	free(*line);
	ft_memcpy(new_line + size_line, buf, size_util);
	*line = new_line;
}

int	add_utils(char *buf, char **line, int *size_line, int size_read)
{
	int	size_util;

	size_util = end_line_pos(buf, size_read);
	if (size_util > 0)
	{
		add_to_line(line, buf, size_util, *size_line);
		*size_line += size_util;
	}
	return (size_util);
}

int	end_line_parm(char *buf, int *cursor, int size_read, int size_util)
{
	int	end_line;

	end_line = 1;
	if ((*cursor + size_util) == size_read)
		end_line = 0;
	if (end_line && (size_util + 2) <= (size_read - *cursor))
	{
		*cursor += size_util + 1;
	}
	else
	{
		*buf = 0;
		*cursor = 0;
	}
	return (end_line);
}
