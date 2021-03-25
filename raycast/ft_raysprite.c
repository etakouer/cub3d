/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raysprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:10:13 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/24 15:30:36 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_raycast.h"

void	ft_put_sprite(t_mlx *mlx, t_cast *cast, int x)
{
	unsigned int	*adr;
	t_point			p;
	int				t;

	adr = ft_mlx_pixel_get(&mlx->sp_txt, (int)cast->a.x, (int)cast->a.y);
	p.x = x + cast->p.y;
	p.y = cast->img.h / 2 - cast->h / 2 + cast->p.x;
	t = (*adr != 0);
	if (TRSP)
		t = (*adr & (0xFF << 24)) != 0xFF000000;
	if (t)
		ft_mlx_pixel_put(&cast->img, p.x, p.y, *adr);
}

void	ft_print_sprite(t_mlx *mlx, t_cast *cast, t_sprite *sprite, int x)	
{
	double	step;

	step = 64.0 / cast->h;
	cast->p.y = -1;
	cast->a.x = 0;
	while (++cast->p.y < cast->h)
	{
		if ((x + cast->p.y) < cast->img.w && (x + cast->p.y) >= 0)
		{
			if (mlx->px[x + cast->p.y] - sprite->dist > 0.0)
			{
				cast->p.x = -1;
				cast->a.y = 0;
				while (++cast->p.x < cast->h)
				{
					ft_put_sprite(mlx, cast, x);
					cast->a.y += step;
				}
			}
		}
		cast->a.x += step;
	}
}

void	ft_raysprit(t_mlx *mlx, t_cast *cast, t_sprite *sprite)
{
	double	alpha;
	double	beta;
	double	fov_max;
	int		x;

	cast->h = ceil((mlx->map->bsize * mlx->config->dist * 1.0) / sprite->dist);
	fov_max = mlx->map->dir + MFOV;
	alpha = atan2((sprite->spc.y - cast->g.y), (sprite->spc.x - cast->g.x));
	beta = fov_max + alpha;
	if (ceil(beta) >= 2.0 * M_PI)
		beta -= 2.0 * M_PI;
	x = floor(ft_todeg(beta) * (cast->img.w * 1.0) / ft_todeg(FOV));
	x -= cast->h / 2;
	ft_print_sprite(mlx, cast, sprite, x);
}

void	ft_draw_sprites(t_mlx *mlx, t_cast *cast)	
{
	int	i;

	i = 0;
	cast->p.x = -1;
	cast->e_dir = mlx->map->dir + MFOV;
	cast->sp = 1;
	ft_set_spdist(mlx);
	ft_sort_sprite(mlx);
	i = 0;
	while (i < mlx->map->nbsp)
	{
		ft_raysprit(mlx, cast, &mlx->map->sprites[i]);
		i++;
	}
}
