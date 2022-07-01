/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:31:05 by ciclo-d           #+#    #+#             */
/*   Updated: 2022/07/01 21:18:03 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_count(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

size_t	ft_strlen(char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
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

char	*ft_linejoin(char *full)
{
	char	*s;
	int		i;
	int		j;

	j = ft_slen(full, '\n');
	if (!full)
		return (NULL);
	s = (char *)malloc(j + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (i < j + 1)
	{
		s[i] = full[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_substr(char *full, int start, int len)
{
	char	*s;
	int		i;
	int		j;

	if (!ft_strchr(full, '\n'))
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
