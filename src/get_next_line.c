/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:04:43 by ciclo-d           #+#    #+#             */
/*   Updated: 2022/06/25 14:48:25 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	int		rd;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (rd--)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
	}
	//printf ("%s0", buffer);
	return (buffer);
}

int	main(void)
{
	const char	*s;
	int			fd;

	fd = open("txt/fd.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s\n", s);
}
