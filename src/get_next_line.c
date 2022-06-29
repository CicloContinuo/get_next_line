/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:04:43 by ciclo-d           #+#    #+#             */
/*   Updated: 2022/06/29 12:31:31 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char *str_stc)
{
	char	*temp;
	int		i;
	int		j;

	if (!str_stc)
		return (NULL);
	i = 0;
	while (str_stc[i] != 0 && str_stc[i] != '\n')
		i++;
	temp = (char *)malloc(i + 2);
	if (!temp)
		return (NULL);
	j = 0;
	while (str_stc[j] != 0 && str_stc[j] != '\n')
	{
		temp[j] = str_stc[j];
		j++;
	}
	temp[j] = 0;
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
		str_stc = ft_strjoin (str_stc, buffer);
		ft_strchr (buffer, '\n');
		break ;
	}
	free (buffer);
	return (str_stc);
}

char	*get_next_line(int fd)
{
	char static	*str_stc;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	str_stc = (char *)malloc(BUFFER_SIZE + 1);
	if (!str_stc)
		return (NULL);
	str_stc = ft_read(fd, str_stc);
	line = next_line(str_stc);
	return (line);
}

/*int	main(void)
{
	int		file;
	char	*line;
	int		i;

	file = open("txt/fd.txt", O_RDWR);
	i = 5;
	while (i > 0)
	{
		line = get_next_line(file);
		printf("%s\n", line);
		i--;
	}
}
*/
