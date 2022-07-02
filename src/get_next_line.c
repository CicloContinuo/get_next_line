/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 12:18:41 by ciclo             #+#    #+#             */
/*   Updated: 2022/07/02 19:40:34 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_line(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	j = ft_count(str);
	tmp = (char *)malloc(ft_strlen(str) - j + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != 0)
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	tmp[j] = 0;
	return (tmp);
}

char	*ft_get_line(char *str)
{
	char	*tmp;
	int		j;
	int		i;

	j = ft_count(str);
	tmp = (char *)malloc(sizeof(char) * (j + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_read(int fd, char *str)
{
	char		*buffer;
	ssize_t		rd;

	if (!fd && !str)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	rd = 1;
	while (rd > 0 && !ft_strchr(str, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			return (NULL);
		str = ft_strjoin(str, buffer);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = ft_read(fd, str);
	line = ft_get_line(str);
	str = new_line(str);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("txt/test.txt", O_RDONLY);
	i = 4;
	while (i--)
	{
		line = get_next_line(fd);
		printf("main: %s\n", line);
	}
	return (0);
}
