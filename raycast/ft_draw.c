/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:12:05 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/24 17:35:13 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_raycast.h"

void	ft_draw_sp(t_mlx *mlx, t_img *img)
{
	t_cast	cast;
	double	rat;

	rat = (mlx->map->bsize_m * 1.0) / (mlx->map->bsize * 1.0);
	cast.g = mlx->map->pg;
	cast.b_dir = mlx->map->dir - MFOV;
	while (cast.b_dir <= (mlx->map->dir + MFOV))
	{
		cast.g = mlx->map->pg;
		cast.a = ft_raycastx(mlx, cast.b_dir, 1);
		cast.b = ft_raycasty(mlx, cast.b_dir, 1);
		if (ft_get_dist(cast.a, cast.g) > ft_get_dist(cast.b, cast.g))
			cast.a = cast.b;
		cast.p.x = round(rat * cast.a.x);
		cast.p.y = round(rat * cast.a.y);
		cast.g.x = round(rat * cast.g.x);
		cast.g.y = round(rat * cast.g.y);
		ft_mlx_line_put(img, cast.g, cast.p, WHITE);
		cast.b_dir += mlx->config->step;
	}
	cast.g.x--;
	cast.g.y--;
	ft_mlx_square_put(img, cast.g, RED, 3);
}

void	ft_draw_map(t_mlx *mlx)
{
	t_img	img;

	img.w = mlx->map->bsize_m * mlx->map->w;
	img.h = mlx->map->bsize_m * mlx->map->h;
	if (img.w + img.h > 0)
	{
		ft_img_create(&img, mlx);
		ft_mlx_map_put(&img, mlx->map);
		ft_draw_sp(mlx, &img);
		ft_img_to_win(&img, mlx, 0, 0);
	}
}

void	ft_floor_rays(t_cast *cast)
{
	cast->a.x = floor(cast->a.x);
	cast->a.y = floor(cast->a.y);
	cast->b.x = floor(cast->b.x);
	cast->b.y = floor(cast->b.y);
}

void	ft_draw_rays(t_mlx *mlx, t_cast *cast)
{
	while (cast->p.x < cast->img.w)
	{
		cast->a = ft_raycastx(mlx, cast->e_dir, 1);
		cast->b = ft_raycasty(mlx, cast->e_dir, 1);
		cast->dist_a = ft_get_dist(cast->a, cast->g);
		cast->dist_b = ft_get_dist(cast->b, cast->g);
		ft_floor_rays(cast);
		cast->r = 0;
		if (ft_get_dist(cast->a, cast->g) > ft_get_dist(cast->b, cast->g))
		{
			cast->a = cast->b;
			cast->dist_a = cast->dist_b;
			cast->r = 1;
		}
		mlx->px[cast->p.x] = cast->dist_a;
		cast->dist_a *= cos(mlx->map->dir - cast->e_dir);
		if (round(cast->dist_a) == 0)
			cast->dist_a = 1.1;
		cast->h = ceil(mlx->map->bsize * mlx->config->dist / cast->dist_a);
		cast->p.y = (mlx->config->rh / 2) - cast->h / 2;
		ft_mlx_col_put(cast, mlx);
		cast->p.x++;
		cast->e_dir -= mlx->config->step;
	}
}

void	ft_draw_raycast(t_mlx *mlx)
{
	t_cast	cast;

	cast.img.w = mlx->config->rw;
	cast.img.h = mlx->config->rh;
	ft_img_create(&cast.img, mlx);
	cast.g = mlx->map->pg;
	cast.b_dir = mlx->map->dir - MFOV;
	cast.e_dir = mlx->map->dir + MFOV;
	cast.p.x = 0;
	cast.sp = 0;
	ft_draw_rays(mlx, &cast);
	ft_draw_sprites(mlx, &cast);
	if (mlx->save)
	{
		ft_save(&cast.img);
		printf("Saved in : save_cub3D.bmp\n");
		ft_quit_mlx(mlx);
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	ft_img_to_win(&cast.img, mlx, 0, 0);
}
