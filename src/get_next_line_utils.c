/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 12:18:29 by ciclo             #+#    #+#             */
/*   Updated: 2022/07/02 19:31:14 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_count(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != 0 && str[i] != '\n')
		i++;
	return (i);
}

size_t	ft_strlen(char const	*s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[i]);
	while (s[i] != 0)
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	int			i;
	int			n;

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
	n = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[n] != '\0')
		str[i++] = s2[n++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (0);
	if (ft_strlen(s) > len + start)
		str = (char *)malloc((len + 1) * sizeof(char));
	else if (ft_strlen(s) > start)
		str = (char *)malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		str = (char *)malloc(sizeof(char));
	if (!str)
		return (0);
	i = 0;
	j = start;
	if (start < ft_strlen(s))
	{
		while (s[i] && (i < len) && (j < ft_strlen(s)))
			str[i++] = s[j++];
	}
	str[i] = '\0';
	return (str);
}
