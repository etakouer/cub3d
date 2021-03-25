/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 07:43:19 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/24 11:41:34 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_err(char *msg, char *name_ft, int quit)
{
	printf("Error\n");
	if (msg)
		printf("%s\n", msg);
	else
		printf("%s\n", strerror(errno));
	if (DEBUG)
		printf("{%s}\n", name_ft);
	if (quit)
		exit(0);
}
