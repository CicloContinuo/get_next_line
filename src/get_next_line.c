/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 12:18:41 by ciclo             #+#    #+#             */
/*   Updated: 2022/07/02 14:57:33 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char		*buffer;
	ssize_t		rd;

	if (!fd && !str)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (rd)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			return (NULL);
		buffer[rd] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free (buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char static	*str;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	line = ft_read(fd, str);
	return (line);
}

int	main(void)
{
	char const	*s;
	int			fd;
	int			c;

	c = 2;
	fd = open("txt/test.txt", O_RDONLY);
	while (c--)
	{
		s = get_next_line(fd);
		printf("%s\n", s);
	}
	close (fd);
	return (0);
}
