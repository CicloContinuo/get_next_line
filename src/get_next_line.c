/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:04:43 by ciclo-d           #+#    #+#             */
/*   Updated: 2022/06/27 08:35:46 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	int		rd;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			buffer = (char *)malloc(1);
			buffer[0] = '\0';
			free(buffer);
		}
		buffer[rd] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd <= 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_read(fd, str);
	if (!line)// en la condicion de arriba ya comprobamos si en el fd hay para leer
		return (NULL);
	return (line);
}

int	main(void)
{
	char const	*s;
	int			fd;

	fd = open("txt/fd.txt", O_RDONLY);
	s = get_next_line(fd);
	
	printf ("%s", s);
	close(fd);
}
