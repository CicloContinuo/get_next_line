/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo-d <ciclo-d@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:04:43 by ciclo-d           #+#    #+#             */
/*   Updated: 2022/06/21 15:32:44 by ciclo-d          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*full_str;
	char 		*buffer;
	int			rd;

	if (fd <= 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
	rd = 1;
	while (rd > 0)
		rd = read(fd, buffer, BUFFER_SIZE);
	buffer[rd] = 0;
	printf ("%s\n", buffer);
	return (buffer);
}

int	main(void)
{

	int		fd;

	fd =  open("txt/fd.txt", O_RDONLY);
	char *s = get_next_line(fd);
	printf ("%s\n", s);
	close(fd);
}
