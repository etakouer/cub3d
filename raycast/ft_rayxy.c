/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rayxy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:03:46 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/24 17:24:01 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_raycast.h"

void	ft_get_ray_paramx(t_ray *ray, double dir)
{
	if (sin(dir) > 0.0)
	{
		ray->a.y = (ray->g.y / (int)ray->bsize) * ray->bsize - BETA;
		ray->d.y = -ray->bsize;
	}
	else
	{
		ray->a.y = (ray->g.y / (int)ray->bsize) * ray->bsize + ray->bsize;
		ray->d.y = ray->bsize;
	}
	ray->a.x = ray->g.x + ((ray->g.y - ray->a.y) / ray->tg);
	if (sin(dir) < 0.0)
		ray->tg = -ray->tg;
	ray->d.x = ray->bsize / ray->tg;
	ray->m.x = floor(ray->a.x / ray->bsize);
	ray->m.y = floor(ray->a.y / ray->bsize);
}

t_dist	ft_raycastx(t_mlx *mlx, double dir, int wall)
{
	t_ray	ray;

	ray.k.x = BIGN;
	ray.k.y = BIGN;
	ray.g = mlx->map->pg;
	ray.bsize = mlx->map->bsize * 1.0;
	ray.tg = tan(dir);
	if (ray.tg == 0.0)
		return (ray.k);
	ft_get_ray_paramx(&ray, dir);
	while (ft_true_index(mlx, ray.m))
	{
		if (ft_next(mlx, &ray, wall))
		{
			ray.a.x += ray.d.x;
			ray.a.y += ray.d.y;
			ray.m.x = floor(ray.a.x / ray.bsize);
			ray.m.y = floor(ray.a.y / ray.bsize);
		}
		else
			break ;
	}
	if (!ft_true_index(mlx, ray.m))
		return (ray.k);
	return (ray.a);
}

void	ft_get_ray_paramy(t_ray *ray, double dir)
{
	if (cos(dir) < 0.0)
	{
		ray->a.x = (ray->g.x / (int)ray->bsize) * ray->bsize - BETA;
		ray->d.x = -ray->bsize;
	}
	else
	{
		ray->a.x = (ray->g.x / (int)ray->bsize) * ray->bsize + ray->bsize;
		ray->d.x = ray->bsize;
	}
	ray->a.y = ray->g.y + (ray->g.x - ray->a.x) * ray->tg;
	if (cos(dir) > 0.0)
		ray->tg = -ray->tg;
	ray->d.y = ray->bsize * ray->tg;
	ray->m.x = floor(ray->a.x / ray->bsize);
	ray->m.y = floor(ray->a.y / ray->bsize);
}

t_dist	ft_raycasty(t_mlx *mlx, double dir, int wall)
{
	t_ray	ray;

	ray.k.x = BIGN;
	ray.k.y = BIGN;
	ray.g = mlx->map->pg;
	ray.bsize = mlx->map->bsize * 1.0;
	ray.tg = tan(dir);
	ft_get_ray_paramy(&ray, dir);
	while (ft_true_index(mlx, ray.m))
	{
		if (ft_next(mlx, &ray, wall))
		{
			ray.a.x += ray.d.x;
			ray.a.y += ray.d.y;
			ray.m.x = floor(ray.a.x / ray.bsize);
			ray.m.y = floor(ray.a.y / ray.bsize);
		}
		else
			break ;
	}
	if (!ft_true_index(mlx, ray.m))
		return (ray.k);
	return (ray.a);
}
