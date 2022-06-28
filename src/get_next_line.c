/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:04:43 by ciclo-d           #+#    #+#             */
/*   Updated: 2022/06/28 23:02:58 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

char	*ft_cut(char *str)
{
	char	*temp;
	int		count_pos;
	int		count_line;

	count_line = 0;
	count_pos = 0;
	while (str[count_pos] != '\n' && str[count_pos] != 0)
		count_pos++;
	temp = (char *)malloc(sizeof (char) * count_pos);
	if (!temp)
		return (NULL);
	count_pos = 0;
	while (str[count_pos] == '\n' && str[count_pos] != 0)
	{
		temp[count_line++] = str[count_line++];
		count_pos++;
	}
	return (temp);
}

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	int		rd;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		str = ft_strjoin(str, buffer);
		ft_strchr(buffer, '\n');
		break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd <= 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_read(fd, str)'¿009'9'9'''
	return (line);
}

int	main(void)
{
	char const	*s;
	int			fd;

	fd = open("txt/fd.txt", O_RDONLY);
	s = get_next_line(fd);
	printf ("%s", s);
	close(fd);
}
