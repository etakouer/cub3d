/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:04:58 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/24 11:50:06 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_free_data(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->h)
	{
		if (map->data[y] != NULL)
		{
			free(map->data[y]);
			map->data[y] = NULL;
		}
		y++;
	}
	free(map->data);
	map->data = NULL;
}

void	ft_free_config(t_config *c)
{
	int		i;
	char	***p;

	p = (char **[5]){&c->no, &c->so, &c->ea, &c->we, &c->s};
	i = -1;
	while (++i < 5)
	{
		if (p[i] != NULL)
		{
			free(*(p[i]));
			*(p[i]) = NULL;
		}
	}
}

void	ft_free_mlx(t_mlx *mlx, t_config *config, t_map *map)
{
	(void)mlx;
	if (config != NULL)
	{
		ft_free_config(config);
		free(config);
		config = NULL;
	}
	if (map != NULL)
	{
		if (map->data != NULL)
		{
			ft_free_data(map);
			free(map->data);
			map->data = NULL;
		}
		free(map);
		map = NULL;
	}
	exit(0);
}

void	ft_destroy_mlx(t_mlx *m)
{
	t_img	**g;
	int		i;

	g = (t_img *[5]){&m->n_txt, &m->s_txt, &m->e_txt, &m->w_txt, &m->sp_txt};
	if (m != NULL && m->mlx != NULL)
	{
		i = -1;
		while (++i < 5)
			mlx_destroy_image(m->mlx, g[i]->img);
		mlx_destroy_window(m->mlx, m->win);
	}
}

int	ft_quit_mlx(t_mlx *mlx)
{
	ft_destroy_mlx(mlx);
	ft_free_mlx(mlx, mlx->config, mlx->map);
	return (0);
}
