/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo-d <ciclo-d@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:31:05 by ciclo-d           #+#    #+#             */
/*   Updated: 2022/06/21 13:27:48 by ciclo-d          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char *buffer, char *full_str)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!buffer && !full_str)
		return (NULL);
	str = (char *)malloc(ft_strlen(full_str) + 1);
	i = 0;
	j = 0;
	while (buffer[i] != 0)
	{
		str[i] = buffer[i];
		i++;
	}
	while (full_str[j] != 0)
	{
		str[i + j] = full_str[j];
		j++;
	}
	str[i + j] = 0;
	free (buffer);
	return (str);
}
