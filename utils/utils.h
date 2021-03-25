/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:44:34 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/24 14:10:35 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "const.h"

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_dist
{
	double	x;
	double	y;
}			t_dist;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	t;
}		t_color;

typedef struct s_config
{
	int		rw;
	int		rh;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		f;
	int		c;
	double	dist;
	double	step;
	double	speed;
	int		check[NB_PARAM];
}			t_config;

typedef struct s_sprite
{
	t_dist	spc;
	double	dist;
}			t_sprite;

typedef struct s_map
{
	int			**data;
	int			w;
	int			h;
	t_point		mg;
	t_point		pg;
	double		dir;
	int			bsize;
	int			bsize_m;
	t_sprite	sprites[NBSP];
	int			nbsp;
	int			nbg;
}				t_map;

typedef struct s_data
{
	char	**data;
	int		w;
	int		h;
}				t_data;

typedef struct s_ray
{
	t_point	g;
	double	bsize;
	t_dist	a;
	t_dist	d;
	double	tg;
	t_point	m;
	t_dist	k;
}			t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		edn;
	int		w;
	int		h;
}			t_img;

typedef struct s_cast
{
	t_dist	a;
	t_dist	b;
	t_point	g;
	double	b_dir;
	double	e_dir;
	double	dist_a;
	double	dist_b;
	t_point	p;
	int		h;
	t_img	img;
	int		r;
	int		sp;
	t_point	m;
}			t_cast;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	int			save;
	t_config	*config;
	t_map		*map;
	t_img		n_txt;
	t_img		s_txt;
	t_img		e_txt;
	t_img		w_txt;
	t_img		sp_txt;
	double		px[NBPX];
}				t_mlx;

void			*ft_memcpy(void *dst, const void *src, size_t n);
size_t			ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s1);
char			**ft_split(char const *s, char c);
int				ft_isdigit(int c);
void			ft_err(char *msg, char *name_ft, int quit);
void			ft_free_mlx(t_mlx *mlx, t_config *config, t_map *map);
void			ft_print_map(t_map *map);
int				ft_atoi(const char *str);
double			ft_torad(double deg);
double			ft_todeg(double rad);
int				ft_create_trgb(t_color color);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_print_config(t_config *config);
int				ft_quit_mlx(t_mlx *mlx);
void			ft_print_checks(int *tab);

#endif
