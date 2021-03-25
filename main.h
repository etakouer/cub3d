/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:05:57 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/03 15:52:42 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "parser/ft_parser.h"
# include "raycast/ft_raycast.h"
# include "utils/utils.h"

void	ft_check_args(int ac, char **av, int *fd, int *save);

#endif
