/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytxt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:07:32 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/24 17:07:36 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_raycast.h"

t_img	*ft_get_imgtxt(t_cast *cast, t_mlx *mlx)
{
	if (cast->r > 0 && cast->a.x - cast->g.x > 0)
		return (&mlx->e_txt);
	if (cast->r > 0 && cast->a.x - cast->g.x < 0)
		return (&mlx->w_txt);
	if (cast->r == 0 && cast->a.y - cast->g.y > 0)
		return (&mlx->s_txt);
	return (&mlx->n_txt);
}

unsigned int	*ft_mlx_pixel_get(t_img *data, int x, int y)
{
	unsigned int	*adr;

	adr = (unsigned int *)(data->addr + (y * data->len + x * (data->bpp / 8)));
	return (adr);
}

void	ft_mlx_txt_put(t_cast *cast, t_mlx *mlx)
{
	double			step;
	double			j;
	t_img			*img;
	unsigned int	*adr;

	img = ft_get_imgtxt(cast, mlx);
	j = 0;
	step = 64.0 / cast->h;
	while (cast->h--)
	{
		if (cast->r == 0)
			adr = ft_mlx_pixel_get(img, (int)(cast->a.x) % 64, (int)j);
		else
			adr = ft_mlx_pixel_get(img, (int)(cast->a.y) % 64, (int)j);
		if (cast->p.y >= 0 && cast->p.y < mlx->config->rh)
		{
			ft_mlx_pixel_put(&cast->img, cast->p.x, cast->p.y, *adr);
		}
		cast->p.y++;
		j = j + step;
	}
}

void	ft_mlx_col_put(t_cast *cast, t_mlx *mlx)
{
	int	i;

	i = 0;
	if (cast->p.y >= 0 && cast->p.y < cast->img.h)
		while (i < cast->p.y)
			ft_mlx_pixel_put(&cast->img, cast->p.x, i++, mlx->config->c);
	i += cast->h;
	ft_mlx_txt_put(cast, mlx);
	while (i > 0 && i < cast->img.h)
		ft_mlx_pixel_put(&cast->img, cast->p.x, i++, mlx->config->f);
}
