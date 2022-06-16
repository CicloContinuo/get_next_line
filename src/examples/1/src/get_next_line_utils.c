/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:58:35 by ciclo             #+#    #+#             */
/*   Updated: 2022/06/16 22:08:44 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	u;

	if (!str)
		return (0);
	u = 0;
	while (str[u])
		u++;
	return (u);
}
