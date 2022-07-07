/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:11:17 by dugonzal          #+#    #+#             */
/*   Updated: 2022/07/07 00:04:50 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


/*char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (BUFFER_SIZE < 1)
		return (NULL);
	str = ft_read(fd, str); //leo y almaceno en la variable estatica
	//line = ft_strdup(str);// copio en una variable estatica la primera linea
	//str = ft_substr(str, ft_slen(str, '\n'), ft_slen(str, '\0')); // copia la segunda de la variable estatica
	return (line);
}*/

/*char	*sub_line(char *str)
{
	char	*tmp;
	int		i;
	int 	j;

	j = ft_slen(str, '\n');
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) - j + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	j++;
	while (str[i] != 0)
	{
		tmp[i] = str[j];
		i++;
	}
	//printf ("%s", tmp);
	tmp[i] = '\0';
	return (tmp);
}
*/

char*ft_read(int fd, char *str)
{
	char *buffer;
	int		rd;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (rd)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		buffer[rd] = 0;
		str = ft_strjoin(str, buffer);
	}

	return (str);
}
char	*get_next_line(int fd)
{
	static char	*str;

	if (BUFFER_SIZE < 1)
		return (NULL);
	str = ft_read(fd, str);
	return (str);
}

/*int	main(void)
{
	char	*s;
	int			fd;
	int			c;

	fd = open("txt/fd.txt", O_RDONLY);
	c = 1;
	while (c--)
	{
		s = get_next_line(fd);
		printf ("MAIN:%s\n", s);
	}
	close(fd);
	return (0);
}
*/
/*
 tenemos que leer x bytes por vez, luego copiarlos a una variable temporal,
x bytes mientras leemos,
 hasta el final de la primera linea y luego copiar esa linea
 */
