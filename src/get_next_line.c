/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:04:43 by ciclo-d           #+#    #+#             */
/*   Updated: 2022/06/29 16:37:49 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		ft_strchr(str_stc, '\n');
		break ;
	}
	free (buffer);
	return (str_stc);
}

char	*get_next_line(int fd)
{
	static char	*str_stc;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_read(fd, str_stc);
	i = 0;
	while (str_stc[i] && str_stc[i] != '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (str_stc[i] == '\n')
	{
		line[i] = str_stc[i];
		i++;
	}
	line[i] = '\0';
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
