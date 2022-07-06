/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:31:05 by ciclo-d           #+#    #+#             */
/*   Updated: 2022/07/06 12:11:21 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char *full, char *buffer)
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

char	*ft_substr(char *full, int start, int len)
{
	char	*s;
	int		i;
	int		j;

	if (!ft_strchr(full, '\n') || start >= len)
	{
		free(full);
		return (NULL);
	}
	s = (char *)malloc((len - start + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (i < start)
		i++;
	while (i < len)
		s[j++] = full[i++];
	s[j] = '\0';
	free (full);
	return (s);
}

char	*ft_strchr(char *full, char c)
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
