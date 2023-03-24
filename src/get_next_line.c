/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:11:17 by dugonzal          #+#    #+#             */
/*   Updated: 2022/12/12 19:46:48 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer)
{
	free (buffer);
	return (NULL);
}

char	*ft_line(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i] != 0 && str[i] != '\n')
		i++;
  if (str[i] == '\0')
  {
    free (str);
    return (NULL);
  }
	tmp = (char *)malloc(sizeof (char) * (i + 2));
	i = 0;
  *tmp = '\0';
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
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_read(char *str, int fd)
{
	char	*buffer;
	ssize_t	rd;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_find(str, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			return (ft_free(buffer));
		buffer[rd] = '\0';
		str = ft_join(str, buffer);
    if (rd < 1)
      break;
	}
	free(buffer);
	return (str);
}

char	*ft_sub_str(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (str[i] != 0 && str[i] != '\n')
		i++;
  if (!str[i])
    return (NULL);
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) - i) + 2);
	if (!tmp)
		return (NULL);
	j = 0;
	while (str[i] != 0)
		tmp[j++] = str[++i];
	tmp[j] = 0;
	free (str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	str = ft_read(str, fd);
	if (!str)
		return (NULL);
	line = ft_line(str);
	str = ft_sub_str(str);
	return (line);
}
