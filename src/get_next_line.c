/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:11:17 by dugonzal          #+#    #+#             */
/*   Updated: 2022/07/02 12:01:12 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_str(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = ft_count(str);
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!tmp)
		return (NULL);
	j = 0;
	i++;
	while (str[i] != 0)
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	//printf ("new: %s\n" , (tmp));
	tmp[j] = '\0';
	//free(tmp);
	return (tmp);
}

char	*ft_line(char *str)
{
	char	*tmp2;
	int		i;

	i = ft_count(str);
	tmp2 = (char *)malloc(sizeof(char) * i + 2);
	if (!tmp2)
		return (NULL);
	i = 0;
	while (str[i] != 0 && str[i] != '\n')
	{
		tmp2[i] = str[i];
		i++;
	}
	tmp2[i] = 0;
	return (tmp2);
}

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	int		rd;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	rd = BUFFER_SIZE;
	while (rd)
	{
		if (ft_strchr(buffer, '\n'))
			break ;
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			return (NULL);
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

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = ft_read(fd, str);
	if (str == NULL)
		return (NULL);
	line = ft_line(str);
	str = ft_new_str(str);
	return (line);
}

/*int	main(void)
{
	char const	*s;
	int			fd;
	int			c;

	fd = open("txt/fd.txt", O_RDONLY);
	c = 3;
	while (c--)
	{
		s = get_next_line(fd);
		printf ("MAIN :%s\n", s);
	}
	close(fd);
	return (0);
}*/

/*
** **************************************************************************
	pajaros = 8
	los casos en los casos que debemos cotrolar es cuando hay un salto de linea,
	('\n') y cuando es 0 el filedescriprtor
 	si meto el el malloc dentro del while se creara una vez la reservea de memoria o en cada vuelta?

 */
