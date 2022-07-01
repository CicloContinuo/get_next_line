/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:11:17 by dugonzal          #+#    #+#             */
/*   Updated: 2022/07/01 20:30:49 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_count(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_line(char *str)
{
	char	*tmp;
	int		i;

	i = ft_count(str);
	tmp = (char *)malloc(sizeof(char) * i + 2);
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i++] != 0 && str[i++] != '\n')
		tmp[i] = str[i];
	while (str[i++] == '\n')
		tmp[i] += i;
	tmp[i] = 0;
	free (tmp);
	return (tmp);
}

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	int		rd;

	rd = BUFFER_SIZE;
	while (rd)
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		str = ft_strjoin(str, buffer);
		ft_strchr(str, '\n');
		break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = ft_read(fd, str);
	if (str == NULL)
		return (NULL);
	line = ft_line(str);
	return (line);
}

int	main(void)
{
	char const	*s;
	int			fd;
	int			c;

	fd = open("txt/fd.txt", O_RDONLY);
	c = 1;
	while (c--)
	{
		s = get_next_line(fd);
		printf ("MAIN :%s\n", s);
	}
	close(fd);
}

/*
	los casos en los casos que debemos cotrolar es cuando hay un salto de linea,
	 ('\n') y cuando es 0 el filedescriprtor
 */
