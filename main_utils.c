/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:51:44 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/24 12:03:18 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_check_args(int argc, char **argv, int *fd, int *save)
{
	if (argc < 2 || argc > 3)
		ft_err(ERR_ARGS, "ft_check_args", 1);
	*save = 0;
	if (argc > 2)
	{
		*save = (ft_strcmp(argv[2], "--save") == 0);
		if (!(*save))
			ft_err(ERR_ARGS, "ft_check_args", 1);
		*save = 1;
	}
	if (argc > 1)
	{
		if (ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub"))
			ft_err(ERR_FILE, "ft_check_args", 1);
		*fd = open(argv[1], O_RDONLY);
		if (*fd < 0)
			ft_err(NULL, "ft_check_args", 1);
	}
}
