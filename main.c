/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:17:50 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/25 09:18:29 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	int		fd;

	mlx.mlx = NULL;
	ft_check_args(argc, argv, &fd, &mlx.save);
	ft_parser(fd, &mlx.config, &mlx.map);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.config->rw, mlx.config->rh, "cub3D");
	ft_raycast(&mlx);
	mlx_loop(mlx.mlx);
	return (EXIT_SUCCESS);
}
