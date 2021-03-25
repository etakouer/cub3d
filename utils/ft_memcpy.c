/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:21:49 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/24 11:47:48 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*cp_dst;

	if (!dst && !src)
		return (NULL);
	cp_dst = dst;
	while (n)
	{
		*(unsigned char *)cp_dst = *(unsigned char *)src;
		cp_dst++;
		src++;
		n--;
	}
	return (dst);
}
