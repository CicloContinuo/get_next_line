/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:31:05 by ciclo-d           #+#    #+#             */
/*   Updated: 2022/12/12 19:47:54 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i++] != 0)
		;
	return (i);
}

int	ft_slen(char *string, char c)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i])
	{
		if (string[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_join(char *full, char *buffer)
{
	char	*s;
	int		i;
	int		j;

	if (!full)
	{
		full = malloc(1);
		*full = '\0';
	}
	s = (char *)malloc(ft_slen(full, 0) + ft_slen(buffer, 0) + 1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (full[i])
	{
		s[i] = full[i];
		i++;
	}
	while (buffer[j] != 0)
		s[i++] = buffer[j++];
	free (full);
	s[i] = '\0';
	return (s);
}

char	*ft_find(char *full, char c)
{
	int	i;

	if (!full)
		return (NULL);
	i = 0;
	while (full[i])
	{
		if (full[i] == c)
			return (full + i);
		i++;
	}
	return (NULL);
}
