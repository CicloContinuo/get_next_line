
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo-d <ciclo-d@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:04:43 by ciclo-d           #+#    #+#             */
/*   Updated: 2022/06/23 15:41:43 by ciclo-d          ###   ########.fr       */
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
	while (!ft_strchr(buffer, '\n')) //  !ft_strchr
	{
		rd = read(fd, buffer, BUFFER_SIZE); // usamos read y lo guardamos en la variuable rd
		if (rd == -1) // condicion del fallo del read en la lectura
		{
			buffer = malloc(sizeof(1)); //reserva del '\0';
			buffer[rd] =  '\0'; // ponemos   '\0'
			free(buffer); //liberamos buffer
		}
		buffer[rd] = '\0'; //  ponemos '\0' al final del string.
		str = ft_strjoin(str, buffer);// aqui estamos usando join, que otra se podria usar//
	}
	free(buffer); // liberamos la memoria reservada para laq varible buffer
	return (str); // retorno del string
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd <= 0 || BUFFER_SIZE < 1)
		return (NULL);
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
