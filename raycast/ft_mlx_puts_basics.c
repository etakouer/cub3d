/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_puts_basics.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:50:40 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/18 08:32:19 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_raycast.h"

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_mlx_line_put(t_img *img, t_point a, t_point b, int color)
{
	t_dist	d;
	t_dist	p;
	double	step;
	int		i;

	d.x = (b.x - a.x);
	d.y = (b.y - a.y);
	if (fabs(d.x) > fabs(d.y))
		step = fabs(d.x);
	else
		step = fabs(d.y);
	d.x /= step;
	d.y /= step;
	p.x = a.x;
	p.y = a.y;
	i = 1;
	while (i <= step)
	{
		ft_mlx_pixel_put(img, p.x, p.y, color);
		p.x += d.x;
		p.y += d.y;
		i++;
	}
}

void	ft_mlx_square_put(t_img *img, t_point p, int color, int size)
{
	t_point	a;
	t_point	b;
	int		i;

	a.x = p.x;
	a.y = p.y;
	b.x = a.x + size;
	b.y = a.y;
	i = 0;
	while (i < size)
	{
		ft_mlx_line_put(img, a, b, color);
		a.y++;
		b.y = a.y;
		i++;
	}
}

void	ft_mlx_wline_put(t_mlx *mlx, t_point a, t_point b, int color)
{
	t_dist	d;
	t_dist	p;
	double	step;
	int		i;

	d.x = (b.x - a.x);
	d.y = (b.y - a.y);
	if (fabs(d.x) > fabs(d.y))
		step = fabs(d.x);
	else
		step = fabs(d.y);
	d.x /= step;
	d.y /= step;
	p.x = a.x;
	p.y = a.y;
	i = 1;
	while (i <= step)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, p.x, p.y, color);
		p.x += d.x;
		p.y += d.y;
		i++;
	}
}
