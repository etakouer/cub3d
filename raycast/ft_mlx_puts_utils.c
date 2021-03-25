/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:13:45 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/20 13:09:13 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_raycast.h"

int	ft_get_color_map(int v)
{
	if (v == WALL)
		return (GREEN);
	if (v == SPIRIT)
		return (ORANGE);
	if (v == EMPTY)
		return (BLUE);
	return (NONE);
}

int	ft_true_index(t_mlx *mlx, t_point m)
{
	if (m.x < 0 || m.y < 0)
		return (0);
	if (m.y >= mlx->map->h || m.x >= mlx->map->w)
		return (0);
	return (1);
}
