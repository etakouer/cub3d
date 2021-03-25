/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_config.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:52:22 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/25 07:56:42 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

t_config	*ft_create_config(int fd, char **line)
{
	int			gnl;
	char		**strs;
	t_config	*config;

	config = (t_config *)malloc(sizeof(t_config) * 1);
	ft_init_check(config);
	gnl = 1;
	while (gnl)
	{
		gnl = get_next_line(fd, line);
		if (*line == NULL)
			break ;
		strs = ft_split(*line, ' ');
		if (strs == 0 || *strs == 0 || strs[0][0] == '\n' || strs[0][0] == 0)
		{
			free(*line);
			*line = NULL;
			ft_free_strs(&strs);
			continue ;
		}
		if (!ft_check_continue(&strs, config, line))
			break ;
	}
	ft_check_config(config);
	return (config);
}

void	ft_free_strs(char ***strs)
{
	int	i;

	i = 0;
	while ((*strs)[i])
	{
		free((*strs)[i]);
		i++;
	}
	free(*strs);
	*strs = NULL;
}

void	ft_init_check(t_config *c)
{
	int		i;
	char	***p;

	i = -1;
	while (++i < NB_PARAM)
		c->check[i] = 0;
	i = -1;
	p = (char **[5]){&c->no, &c->so, &c->ea, &c->we, &c->s};
	while (++i < 5)
		*(p[i]) = NULL;
}

void	ft_check_config(t_config *config)
{
	int		i;
	char	**c;

	c = (char *[NB_PARAM]){"R", "NO", "SO", "WE", "EA", "S", "F", "C"};
	i = -1;
	if (DEBUG)
		ft_print_checks(config->check);
	while (++i < NB_PARAM)
	{
		if (config->check[i] != 1)
		{
			ft_err(ERR_CONF, "ft_check_config", 0);
			printf("=> %s\n", c[i]);
			ft_free_mlx(NULL, config, NULL);
		}
	}
}

int	ft_check_continue(char ***strs, t_config *config, char **line)
{
	int	s;

	if (*strs)
	{
		s = ft_som_check(config);
		ft_set_res(*strs, config);
		ft_set_text(*strs, config);
		ft_set_colors(*strs, config, *line);
		if (ft_isdigit(*(*(strs[0]))))
		{
			ft_free_strs(strs);
			return (0);
		}
		ft_free_strs(strs);
		free(*line);
		*line = NULL;
		if (ft_som_check(config) == s)
			return (0);
	}
	return (1);
}
