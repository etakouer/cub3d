/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_config_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:56:20 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/25 08:03:00 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_som_check(t_config *config)
{
	int	i;
	int	s;

	s = 0;
	i = -1;
	while (++i < NB_PARAM)
		s += config->check[i];
	return (s);
}

int	ft_isvalid_color(t_color color)
{
	int	*c;
	int	i;

	c = (int [3]){color.r, color.g, color.b};
	i = -1;
	while (++i < 3 && c[i] > -1 && c[i] < 256)
		;
	return (i == 3);
}

void	ft_replace_fc(char *str)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 'F' || str[i] == 'C')
		{
			str[i] = ' ';
			break ;
		}			
	}
	i = -1;
	j = 0;
	k = 0;
	while (str[++i] && k < 4)
	{
		if (str[i] == ',' && ++j)
			k = 0;
		if (ft_isdigit(str[i]))
			k++;
	}
	if (j != 2 || k > 3)
		str[0] = 0;
}

void	ft_put_color(char **strs, t_config *config, t_color color)
{
	if (!ft_strcmp(strs[0], "F"))
	{
		config->f = ft_create_trgb(color);
		config->check[6]++;
	}
	if (!ft_strcmp(strs[0], "C"))
	{
		config->c = ft_create_trgb(color);
		config->check[7]++;
	}
}

void	ft_set_colors(char **strs, t_config *config, char *line)
{
	t_color	color;
	char	**tmp;

	if (!ft_strcmp(strs[0], "F") || !ft_strcmp(strs[0], "C"))
	{
		ft_replace_fc(line);
		tmp = ft_split(line, ',');
		if (tmp && tmp[0] && tmp[1] && tmp[2] && tmp[3] == NULL)
		{
			color.r = ft_validate_nb(tmp[0]);
			color.g = ft_validate_nb(tmp[1]);
			color.b = ft_validate_nb(tmp[2]);
			color.t = 0;
			ft_free_strs(&tmp);
			if (ft_isvalid_color(color))
			{
				ft_put_color(strs, config, color);
			}
		}
	}
}
