/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 07:05:54 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/24 11:15:27 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_raycast.h"

void	ft_get_texture_img(t_mlx *m, t_config *c)
{
	t_img	**g;
	char	**p;
	int		i;
	t_img	*ig;

	p = (char *[5]){c->no, c->so, c->ea, c->we, c->s};
	g = (t_img *[5]){&m->n_txt, &m->s_txt, &m->e_txt, &m->w_txt, &m->sp_txt};
	i = -1;
	while (++i < 5)
	{
		ig = g[i];
		ig->img = mlx_xpm_file_to_image(m->mlx, p[i], &ig->w, &ig->h);
		if (ig->img == NULL)
		{
			ft_err(".cub : Texture path", "ft_get_texture_img", 0);
			printf("=> %s\n", p[i]);
			ft_free_mlx(m, c, m->map);
		}
		ig->addr = mlx_get_data_addr(ig->img, &ig->bpp, &ig->len, &ig->edn);
	}
}

void	ft_init_map(t_mlx *mlx)
{
	int		bsize;
	double	hsize;
	double	wsize;

	hsize = mlx->config->rh / mlx->map->h;
	wsize = mlx->config->rw / mlx->map->w;
	mlx->map->bsize_m = floor(fmin(hsize, wsize)) * RATMAP;
	bsize = mlx->map->bsize;
	mlx->config->speed = mlx->map->bsize * STEP_MOVE;
	mlx->map->pg.x = ((mlx->map->mg.x + 1) * bsize) - (bsize / 2);
	mlx->map->pg.y = ((mlx->map->mg.y + 1) * bsize) - (bsize / 2);
	mlx->config->dist = ((mlx->config->rw * 1.0) / 2.0) / tan(MFOV);
	mlx->config->step = FOV / (mlx->config->rw * 1.0);
	ft_get_texture_img(mlx, mlx->config);
}

void	ft_raycast(t_mlx *mlx)
{
	ft_init_map(mlx);
	ft_draw_raycast(mlx);
	ft_draw_map(mlx);
	mlx_hook(mlx->win, 2, 1L << 0, ft_mlx_keypress_hook, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, ft_quit_mlx, mlx);
}
