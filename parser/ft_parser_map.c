/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:59:13 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/24 11:32:27 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_create_elmt(t_data *data, t_map *map, t_point *m)
{
	m->x = 0;
	while (data->data[m->y][m->x])
	{
		ft_add_data_elmt(data->data[m->y][m->x], map, *m);
		m->x++;
	}
	if (DEBUG)
		printf("%s\n", data->data[m->y]);
	free(data->data[m->y]);
	data->data[m->y] = NULL;
	while (m->x < map->w)
	{
		map->data[m->y][m->x] = -16;
		m->x++;
	}
}

t_map	*ft_create_map(t_data *data)
{
	t_point	m;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map) * 1);
	map->h = data->h;
	map->w = data->w;
	map->bsize = BSIZE;
	map->data = (int **)malloc(sizeof(int *) * map->h);
	m.y = -1;
	map->nbsp = 0;
	map->nbg = 0;
	while (++m.y < map->h)
	{
		map->data[m.y] = (int *)malloc(sizeof(int) * map->w);
		ft_create_elmt(data, map, &m);
	}
	free(data->data);
	data->data = NULL;
	free(data);
	data = NULL;
	return (map);
}

t_data	*ft_create_data(int fd, char *line)
{
	t_data	*data;
	int		len;

	data = (t_data *)malloc(sizeof(t_data));
	data->data = (char **)malloc(sizeof(char *) * NBLINE);
	data->h = 0;
	data->w = 0;
	len = 0;
	while (line && *line)
	{
		data->data[data->h] = line;
		len = ft_strlen(line);
		if (len > data->w)
			data->w = len;
		get_next_line(fd, &line);
		data->h++;
	}
	if (line && *line == 0)
		free(line);
	return (data);
}

void	ft_add_data_elmt(char c, t_map *map, t_point m)
{
	t_sprite	*sprite;

	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		map->mg.x = m.x;
		map->mg.y = m.y;
		map->dir = ft_get_dir(c);
		map->data[m.y][m.x] = 0;
		map->nbg++;
	}
	else
		map->data[m.y][m.x] = c - '0';
	if (c == '2')
	{
		sprite = &map->sprites[map->nbsp];
		sprite->spc.x = ((m.x + 1) * map->bsize) - (map->bsize / 2);
		sprite->spc.y = ((m.y + 1) * map->bsize) - (map->bsize / 2);
		map->nbsp++;
	}
}

double	ft_get_dir(char c)
{
	if (c == 'S')
		return (M_PI * 3.0 / 2.0);
	if (c == 'W')
		return (M_PI);
	if (c == 'N')
		return (M_PI / 2.0);
	return (0);
}
