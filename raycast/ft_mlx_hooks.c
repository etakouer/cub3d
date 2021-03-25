/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:55:05 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/22 07:46:18 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_raycast.h"

void	ft_mlx_movey_hook(t_mlx *mlx, double step)
{	
	t_point	m;
	t_point	d;

	d.y = round(sin(mlx->map->dir) * mlx->config->speed);
	d.x = round(cos(mlx->map->dir) * mlx->config->speed);
	m.y = (mlx->map->pg.y + (-d.y * step)) / mlx->map->bsize;
	m.x = (mlx->map->pg.x + (d.x * step)) / mlx->map->bsize;
	if (mlx->map->data[m.y][m.x] == 0)
	{
		mlx->map->pg.y += -d.y * step;
		mlx->map->mg.y = m.y;
		mlx->map->pg.x += d.x * step;
		mlx->map->mg.x = m.x;
		ft_draw_raycast(mlx);
		ft_draw_map(mlx);
	}
}

void	ft_mlx_movex_hook(t_mlx *mlx, double step)
{
	t_point	m;
	t_point	d;

	d.y = round(sin(mlx->map->dir) * mlx->config->speed);
	d.x = round(cos(mlx->map->dir) * mlx->config->speed);
	m.y = (mlx->map->pg.y + (d.x * step)) / mlx->map->bsize;
	m.x = (mlx->map->pg.x + (d.y * step)) / mlx->map->bsize;
	if (mlx->map->data[m.y][m.x] == 0)
	{
		mlx->map->pg.y += d.x * step;
		mlx->map->mg.y = m.y ;
		mlx->map->pg.x += d.y * step;
		mlx->map->mg.x = m.x;
		ft_draw_raycast(mlx);
		ft_draw_map(mlx);
	}
}

void	ft_mlx_dir_hook(t_mlx *mlx, double step)
{
	mlx->map->dir += step;
	if (mlx->map->dir >= 2.0 * M_PI)
		mlx->map->dir -= 2.0 * M_PI;
	if (mlx->map->dir < 0.0)
		mlx->map->dir += 2.0 * M_PI;
	ft_draw_raycast(mlx);
	ft_draw_map(mlx);
}

int	ft_mlx_keypress_hook(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_W)
		ft_mlx_movey_hook(mlx, STEP);
	if (keycode == KEY_S)
		ft_mlx_movey_hook(mlx, -STEP);
	if (keycode == KEY_D)
		ft_mlx_movex_hook(mlx, STEP);
	if (keycode == KEY_A)
		ft_mlx_movex_hook(mlx, -STEP);
	if (keycode == KEY_LEFT)
		ft_mlx_dir_hook(mlx, STEP_DIR);
	if (keycode == KEY_RIGHT)
		ft_mlx_dir_hook(mlx, -STEP_DIR);
	if (keycode == KEY_ESC)
		ft_quit_mlx(mlx);
	return (0);
}
