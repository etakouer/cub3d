/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 07:16:53 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/24 08:19:25 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_raycast.h"

void	ft_save(t_img *img)
{
	int		fd;
	char	*tag;
	int		*tmp;
	t_point	p;

	tag = (char [2]){'B', 'M'};
	tmp = (int [13]){0, 0, 54, 40, 0, 0, 0x200001, 0, 0, 0, 0, 0, 0};
	tmp[0] = 54 + (img->w * img->h * 4);
	tmp[4] = img->w;
	tmp[5] = img->h;
	fd = open("save_cub3D.bmp", O_RDWR | O_CREAT, 0644);
	write(fd, tag, 2);
	write(fd, tmp, 13 * sizeof(int));
	p.y = img->h;
	while (--p.y >= 0)
	{
		p.x = -1;
		while (++p.x < img->w)
			write(fd, ft_mlx_pixel_get(img, p.x, p.y), sizeof(int));
	}
	close(fd);
}
