/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:04:43 by ciclo-d           #+#    #+#             */
/*   Updated: 2022/06/25 14:59:51 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

char	*ft_read(int fd)
{
	char		*buffer;
	int			rd;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (rd--)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		buffer[rd] = 0;
	}
	printf ("%s0", buffer);
	free(buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char *str;
	//char		*line;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	str = ft_read(fd);
	return (str);
}

int	main(void)
{
	const char	*s;
	int			fd;

	fd = open("txt/fd.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s\n", s);
}
