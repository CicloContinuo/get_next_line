/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:52:37 by ciclo             #+#    #+#             */
/*   Updated: 2022/07/04 13:34:08 by ciclo            ###   ########.fr       */
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
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}


int		ft_slen(char *string, char c)
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

	i = ft_slen(full, '\n');
	if (!full)
		return (NULL);
	s = (char *)malloc(i + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (full[i])
	{
		s[i] = full[i];
		i++;
	}
	{
		s[i] = full[i];
		i++;
	}
	//printf("%s", s);
	s[i] = '\0';
	free (full);
	return (s);
}
