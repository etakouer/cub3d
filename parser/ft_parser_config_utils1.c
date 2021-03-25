/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_config_utils1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:04:14 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/24 14:58:12 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_validate_nb(char *str)
{
	int	i;

	i = -1;
	while (str[++i] && (ft_isdigit(str[i]) || str[i] == ' '))
		;
	if (str[i])
		return (-1);
	return (ft_atoi(str));
}

void	ft_set_res(char **strs, t_config *config)
{
	if (!ft_strcmp(strs[0], "R"))
	{
		if (strs[1] && strs[2] && strs[3] == NULL)
		{
			config->rw = ft_validate_nb(strs[1]);
			config->rh = ft_validate_nb(strs[2]);
			if (config->rw > 0 && config->rh > 0)
			{
				if (config->rw > MAX_W)
					config->rw = MAX_W;
				if (config->rh > MAX_H)
					config->rh = MAX_H;
				config->check[0]++;
			}
		}
	}
}

char	*ft_chartxt(t_config *config, char **str, int i)
{
	if (str[1] && str[2] == NULL)
	{
		config->check[i]++;
		return (ft_strdup(str[1]));
	}
	return (NULL);
}

void	ft_set_text(char **strs, t_config *config)
{
	if (!ft_strcmp(strs[0], "NO"))
		config->no = ft_chartxt(config, strs, 1);
	if (!ft_strcmp(strs[0], "SO"))
		config->so = ft_chartxt(config, strs, 2);
	if (!ft_strcmp(strs[0], "WE"))
		config->we = ft_chartxt(config, strs, 3);
	if (!ft_strcmp(strs[0], "EA"))
		config->ea = ft_chartxt(config, strs, 4);
	if (!ft_strcmp(strs[0], "S"))
		config->s = ft_chartxt(config, strs, 5);
}
