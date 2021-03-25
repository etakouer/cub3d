/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 08:11:48 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/20 15:36:05 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAYCAST_H
# define FT_RAYCAST_H

# include "../utils/utils.h"
# include <mlx.h>

void			ft_raycast(t_mlx *mlx);

void			ft_mlx_square_put(t_img *img, t_point p, int color, int size);
void			ft_mlx_line_put(t_img *img, t_point a, t_point b, int color);
void			ft_mlx_wline_put(t_mlx *mlx, t_point a, t_point b, int color);

void			ft_mlx_pixel_put(t_img *img, int x, int y, int color);
void			ft_mlx_map_put(t_img *img, t_map *map);
void			ft_mlx_dir_put(t_img *img, t_mlx *mlx);

int				ft_get_color_map(int v);
int				ft_true_index(t_mlx *mlx, t_point m);

void			ft_mlx_map_put(t_img *img, t_map *map);
void			ft_mlx_dir_put(t_img *img, t_mlx *mlx);
void			ft_mlx_frame_put(t_img *img, int color);

int				ft_mlx_keypress_hook(int keycode, t_mlx *mlx);
void			ft_mlx_dir_hook(t_mlx *mlx, double step);
void			ft_mlx_movex_hook(t_mlx *mlx, double step);
void			ft_mlx_movey_hook(t_mlx *mlx, double step);

void			ft_img_create(t_img *img, t_mlx *mlx);
void			ft_img_to_win(t_img *img, t_mlx *mlx, int x, int y);
double			ft_get_dist(t_dist a, t_point g);
double			ft_get_dist1(t_dist a, t_dist g);
int				ft_next(t_mlx *mlx, t_ray *ray, int wall);

void			ft_get_ray_paramx(t_ray *ray, double dir);
void			ft_get_ray_paramy(t_ray *ray, double dir);
t_dist			ft_raycastx(t_mlx *mlx, double dir, int wall);
t_dist			ft_raycasty(t_mlx *mlx, double dir, int wall);

void			ft_draw_map(t_mlx *mlx);
void			ft_draw_sp(t_mlx *mlx, t_img *img);
void			ft_draw_rays(t_mlx *mlx, t_cast *cast);
void			ft_draw_raycast(t_mlx *mlx);

unsigned int	*ft_mlx_pixel_get(t_img *data, int x, int y);
t_img			*ft_get_imgtxt(t_cast *cast, t_mlx *mlx);
void			ft_mlx_txt_put(t_cast *cast, t_mlx *mlx);
void			ft_mlx_col_put(t_cast *cast, t_mlx *mlx);

void			ft_put_sprite(t_mlx *mlx, t_cast *cast, int x);
void			ft_print_sprite(t_mlx *mlx, t_cast *cast, \
		t_sprite *sprite, int x);
void			ft_raysprit(t_mlx *mlx, t_cast *cast, t_sprite *sprite);
void			ft_draw_sprites(t_mlx *mlx, t_cast *cast);

void			ft_set_spdist(t_mlx *mlx);
void			ft_copy_sprite(t_sprite *sp1, t_sprite *sp2);
void			ft_sort_sprite(t_mlx *mlx);

void			ft_save(t_img *img);

#endif
