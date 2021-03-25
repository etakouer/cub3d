/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:28:35 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/24 11:48:49 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	ft_torad(double deg)
{
	return (deg * M_PI / 180.0);
}

double	ft_todeg(double rad)
{
	return (rad * 180.0 / M_PI);
}

int	ft_create_trgb(t_color color)
{
	return (color.t << 24 | color.r << 16 | color.g << 8 | color.b);
}
