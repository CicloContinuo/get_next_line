/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:48:06 by dugonzal          #+#    #+#             */
/*   Updated: 2022/06/16 14:29:42 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!str1 && !str2)
		return (NULL);
	str = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i] != 0)
	{
		str[i] = str1[i];
		i++;
	}
	while (str2[j] != 0)
	{
		str[i + j] = str2[j];
		j++;
	}
	str[i + j] = 0;
	return (str);
}
