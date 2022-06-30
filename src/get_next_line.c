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

#include "get_next_line.h"

<<<<<<< HEAD
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
=======
/*char	*ft_exptions(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	j = ft_slen(str, '\n');
	tmp = (char *)malloc(j + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i] != 0 && str[i] != '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	return (tmp);
}*/

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	int			rd;
	//char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd <= 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free (buffer);
	//tmp = ft_exptions(str);
>>>>>>> merge
	return (buffer);
}

int	main(void)
{
<<<<<<< HEAD
	int			fd;
	char const	*s;

	fd = open("txt/fd.txt", O_WRONLY);
	s = get_next_line(fd);
	printf ("%s\n", s);
=======
	char const	*s;
	int			fd;
	int			c;

	fd = open("txt/fd.txt", O_RDONLY);
	c = 1;
	while (c--)
	{
		s = get_next_line(fd);
		printf ("%s\n", s);
	}
	close(fd);
>>>>>>> merge
}

/*
	los casos en los casos que debemos cotrolar es cuando hay un salto de linea,
	 ('\n') y cuando es 0 el filedescriprtor
 */
