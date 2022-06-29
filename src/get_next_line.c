/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:04:43 by ciclo-d           #+#    #+#             */
/*   Updated: 2022/06/29 14:32:32 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char *str_stc)
{
	char	*temp;
	int		i;

	if (!str_stc)
		return (NULL);
	i = 0;
	while (str_stc[i] != 0 && str_stc[i] != '\n')
		i++;
	temp = (char *)malloc(i + 2);
	if (!temp)
		return (NULL);
	i = 0;
	while ((str_stc[i] != 0 && str_stc[i] != '\n') || str_stc[i] == '\n')
	{
		temp[i] = str_stc[i];
		i++;
	}
	temp[i] = 0;
	free (temp);
	return (temp);
}

char	*ft_read(int fd, char *str_stc)
{
	char		*buffer;
	ssize_t		rd;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	rd = 1;
	while (rd != 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[rd] = 0;
		str_stc = ft_strjoin(str_stc, buffer);
		ft_strchr (buffer, '\n');
		break ;
	}
	free (buffer);
	return (str_stc);
}

char	*get_next_line(int fd)
{
	static char	*str_stc;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_read(fd, str_stc);
	if (!line)
		return (NULL);
	line = next_line(line);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("txt/fd.txt", O_RDONLY);
	i = 3;
	while (i--)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
	}
	return (0);
}
