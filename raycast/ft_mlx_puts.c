/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:38:37 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/20 14:30:55 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_raycast.h"

void	ft_mlx_map_put(t_img *img, t_map *map)
{
	t_point	m;
	t_point	p;
	int		color;

	m.y = 0;
	while (m.y < map->h)
	{
		m.x = 0;
		while (m.x < map->w)
		{
			color = ft_get_color_map(map->data[m.y][m.x]);
			p.x = m.x * map->bsize_m;
			p.y = m.y * map->bsize_m;
			if ((unsigned int)color != NONE)
				ft_mlx_square_put(img, p, color, map->bsize_m - 1);
			else
				ft_mlx_square_put(img, p, color, map->bsize_m);
			m.x++;
		}
		m.y++;
	}
}

void	ft_mlx_dir_put(t_img *img, t_mlx *mlx)
{
	t_point	a;
	t_point	b;
	int		d;

	d = floor(fmin(img->h, img->w) / 2);
	a.x = floor(img->w / 2);
	a.y = floor(img->h / 2);
	b.x = a.x + d * cos(mlx->map->dir);
	b.y = a.y + d * sin(mlx->map->dir);
	ft_mlx_line_put(img, a, b, WHITE);
	ft_mlx_pixel_put(img, a.x, a.y, RED);
	ft_mlx_pixel_put(img, b.x, b.y, RED);
}

void	ft_mlx_frame_put(t_img *img, int color)
{
	int	i;

	i = 0;
	while (i < img->h)
	{
		ft_mlx_pixel_put(img, 0, i, color);
		ft_mlx_pixel_put(img, img->w - 1, i, color);
		i++;
	}
	i = 0;
	while (i < img->w)
	{
		ft_mlx_pixel_put(img, i, 0, color);
		ft_mlx_pixel_put(img, i, img->h - 1, color);
		i++;
	}
}
