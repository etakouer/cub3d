/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 06:58:14 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/24 14:52:13 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "get_next_line.h"
# include "../utils/utils.h"

int			ft_validate_nb(char *str);
void		ft_set_res(char **strs, t_config *config);
char		*ft_chartxt(t_config *config, char **str, int i);
void		ft_set_text(char **strs, t_config *config);

int			ft_isvalid_color(t_color color);
void		ft_replace_fc(char *str);
void		ft_put_color(char **strs, t_config *config, t_color color);
void		ft_set_colors(char **strs, t_config *config, char *line);
int			ft_som_check(t_config *config);

double		ft_get_dir(char c);
void		ft_add_data_elmt(char c, t_map *map, t_point m);
void		ft_create_elmt(t_data *data, t_map *map, t_point *m);
t_map		*ft_create_map(t_data *data);
t_data		*ft_create_data(int fd, char *line);

int			ft_check_continue(char ***strs, t_config *config, char **line);
void		ft_check_config(t_config *config);
void		ft_init_check(t_config *c);
void		ft_free_strs(char ***strs);
t_config	*ft_create_config(int fd, char **line);

void		ft_check_case(t_map *map, int x, int y, t_config *config);
void		ft_check_map(t_map *map, t_config *config);
void		ft_err_map(t_config *config, char *line);
void		ft_err_data(t_config *config, t_data *data);
void		ft_parser(int fd, t_config **config, t_map **map);

#endif
