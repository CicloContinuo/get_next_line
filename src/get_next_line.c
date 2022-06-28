/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:11:17 by dugonzal          #+#    #+#             */
/*   Updated: 2022/06/28 23:28:31 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	int		rd;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	rd = 0;
	while (rd > 0)
		rd = read(fd, buffer, BUFFER_SIZE);
	printf ("%s\n", buffer);
	return (buffer);
}

int	main(void)
{
	int			fd;
	char const	*s;

	fd = open("txt/fd.txt", O_WRONLY);
	s = get_next_line(fd);
	printf ("%s\n", s);
}
