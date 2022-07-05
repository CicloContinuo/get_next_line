/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:11:17 by dugonzal          #+#    #+#             */
/*   Updated: 2022/07/05 15:15:04 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_count(char *str)
{
	int	i;

	if (str == NULL)
		return (-1);
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
	while (str[i] != 0 && str[i] != '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = 0;
	//free (str);
	return (tmp);
}

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	int		rd;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	rd = BUFFER_SIZE;
	while (rd && (ft_strchr(str, '\n') == NULL))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		buffer[rd] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*ft_new_str(char *str)
{
	char	*tmp;
	int		j;

	j = ft_count(str);
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) - (j + 2)));
	if (!tmp)
		return (NULL);
	j++;
	while (str[j] != '\n' && str[j] != '\0')
	{
		tmp[j] = str[j];
		j++;
	}
	free (str);
	tmp[j] = 0;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = ft_read(fd, str);
	line = ft_line(str);
	str = ft_new_str(str);
	//printf ("str: %s\n", str);
	return (line);
}

int	main(void)
{
	char const	*s;
	int			fd;
	int			c;

	fd = open("txt/fd.txt", O_RDONLY);
	c = 2;
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
