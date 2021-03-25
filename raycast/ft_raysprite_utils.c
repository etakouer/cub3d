/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raysprite_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:12:40 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/23 12:10:11 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_raycast.h"

void	ft_set_spdist(t_mlx *mlx)
{
	int		i;
	double	dist;

	i = 0;
	while (i < mlx->map->nbsp)
	{
		dist = ft_get_dist(mlx->map->sprites[i].spc, mlx->map->pg);
		mlx->map->sprites[i].dist = dist;
		i++;
	}
}

void	ft_copy_sprite(t_sprite *sp1, t_sprite *sp2)
{
	sp1->spc.x = sp2->spc.x;
	sp1->spc.y = sp2->spc.y;
	sp1->dist = sp2->dist;
}

void	ft_sort_sprite(t_mlx *mlx)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < mlx->map->nbsp - 1)
	{
		j = i + 1;
		while (j < mlx->map->nbsp)
		{
			if (mlx->map->sprites[i].dist - mlx->map->sprites[j].dist < 0)
			{
				ft_copy_sprite(&tmp, &mlx->map->sprites[i]);
				ft_copy_sprite(&mlx->map->sprites[i], &mlx->map->sprites[j]);
				ft_copy_sprite(&mlx->map->sprites[j], &tmp);
			}
			j++;
		}
		i++;
	}
}
