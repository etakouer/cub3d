/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:00:41 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/20 15:02:30 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_raycast.h"

void	ft_img_create(t_img *img, t_mlx *mlx)
{
	img->img = mlx_new_image(mlx->mlx, img->w, img->h);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->edn);
}

void	ft_img_to_win(t_img *img, t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, x, y);
	mlx_destroy_image(mlx->mlx, img->img);
}

int	ft_next(t_mlx *mlx, t_ray *ray, int wall)
{
	if (wall)
		return (mlx->map->data[ray->m.y][ray->m.x] != 1);
	return (mlx->map->data[ray->m.y][ray->m.x] == 0);
}

double	ft_get_dist(t_dist a, t_point g)
{
	return (sqrt(pow(a.x - g.x, 2) + pow(a.y - g.y, 2)));
}

double	ft_get_dist1(t_dist a, t_dist g)
{
	return (sqrt(pow(a.x - g.x, 2) + pow(a.y - g.y, 2)));
}
