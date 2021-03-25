/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:19:13 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/24 14:27:23 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_print_map(t_map *map)
{
	t_point	m;

	m.x = 0;
	printf("\n      ");
	while (m.x < map->w)
		printf("%2d ", m.x++);
	printf("\n");
	m.y = 0;
	while (m.y < map->h)
	{
		printf("%2d : |", m.y);
		m.x = 0;
		while (m.x < map->w)
		{
			printf("%2c", map->data[m.y][m.x] + '0');
			m.x++;
			printf("|");
		}
		printf("\n");
		m.y++;
	}
	printf("h: %d w: %d\n\n", map->h, map->w);
}

void	ft_print_checks(int *tab)
{
	int	i;

	i = -1;
	printf("[");
	while (++i < NB_PARAM)
		printf(" %d ", tab[i]);
	printf("]\n");
}

void	ft_print_config(t_config *config)
{
	printf("R %d %d\n", config->rw, config->rh);
	printf("NO %s\n", config->no);
	printf("SO %s\n", config->so);
	printf("WE %s\n", config->we);
	printf("EA %s\n", config->ea);
	printf("S %s\n", config->s);
	printf("F %X\n", config->f);
	printf("C %X\n", config->c);
}
