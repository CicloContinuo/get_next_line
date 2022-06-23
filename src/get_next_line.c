
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo-d <ciclo-d@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:04:43 by ciclo-d           #+#    #+#             */
/*   Updated: 2022/06/22 13:40:13 by ciclo-d          ###   ########.fr       */
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
	while (rd-- && !ft_strchr(buffer, 'n')) //  !ft_strchr
	{
		rd = read(fd, buffer, BUFFER_SIZE);
/*		if (rd == -1)
		{
			buffer = malloc(sizeof(1));
			buffer[rd] =  '\0';
			free(buffer);
		}*/
		buffer[rd] = '\0';
		str = ft_strjoin(str, buffer);// aqui estamos usando join, que otra se podria usar//
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
	//str = ft_read (fd);
	//while (str != 0)
	line = ft_read(fd, str);
	return (line);
}

int	main(void)
{
	int		fd;

	fd =  open("txt/fd.txt", O_RDONLY);
	char *s = get_next_line(fd);
	printf ("%s", s);
	close(fd);
}
