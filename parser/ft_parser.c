/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 08:41:13 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/24 11:07:13 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_check_case(t_map *map, int x, int y, t_config *config)
{
	if (x < 0 || y < 0 || x >= map->w || y >= map->h)
	{
		if (DEBUG)
			printf(".cub : line %d, col %d\n", y, x);
		ft_err(ERR_MAP, "ft_check_case", 0);
		ft_free_mlx(NULL, config, map);
	}
	else
	{
		if (map->data[y][x] > 2 || map->data[y][x] < 0 )
		{
			if (DEBUG)
				printf(".cub : line %d, col %d\n", y, x);
			ft_err(ERR_MAP, "ft_check_case", 0);
			ft_free_mlx(NULL, config, map);
		}
	}
}

void	ft_check_map(t_map *map, t_config *config)
{
	t_point	m;

	if (map->nbg != 1)
	{
		ft_err(ERR_MAP, "ft_check_map", 0);
		printf("=> Gamer position\n");
		ft_free_mlx(NULL, config, map);
	}
	m.y = -1;
	while (++m.y < map->h)
	{
		m.x = -1;
		while (++m.x < map->w)
		{
			if (map->data[m.y][m.x] == 0 || map->data[m.y][m.x] == 2)
			{
				ft_check_case(map, m.x, m.y - 1, config);
				ft_check_case(map, m.x - 1, m.y, config);
				ft_check_case(map, m.x + 1, m.y, config);
				ft_check_case(map, m.x, m.y + 1, config);
			}
		}
	}
}

void	ft_err_map(t_config *config, char *line)
{
	if (line != NULL)
		free(line);
	ft_err(ERR_MAP, "ft_err_map", 0);
	ft_free_mlx(NULL, config, NULL);
}

void	ft_err_data(t_config *config, t_data *data)
{
	while (--data->h >= 0)
		free(data->data[data->h]);
	free(data->data);
	free(data);
	ft_err(ERR_MAP, "ft_err_data", 0);
	ft_free_mlx(NULL, config, NULL);
}

void	ft_parser(int fd, t_config **config, t_map **map)
{
	char	*line;
	t_data	*data;

	line = NULL;
	*config = ft_create_config(fd, &line);
	if (DEBUG)
		ft_print_config(*config);
	if (line == NULL || ft_atoi(line) == 0)
		ft_err_map(*config, line);
	data = ft_create_data(fd, line);
	if (data->h < 3 || data->w < 3)
		ft_err_data(*config, data);
	*map = ft_create_map(data);
	if (DEBUG)
		ft_print_map(*map);
	ft_check_map(*map, *config);
	close(fd);
}
