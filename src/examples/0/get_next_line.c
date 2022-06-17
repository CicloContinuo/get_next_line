/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:48:26 by dugonzal          #+#    #+#             */
/*   Updated: 2022/06/17 09:11:57 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*temp;
	size_t	i;

	temp = (char *)malloc(BUFFER_SIZE + 1)
	if (!temp)
		return (NULL);}
}

int	main(void)
{
	static char	*str;
	int		fd;

	fd = open("prueba/1.txt",O_RDONLY);
	str = get_next_line(fd);
	//printf ("%d",fd);
}
/*char	*get_next_line(int fd)
{
	char *temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!)
		return (NULL);
}*/

/*
	primera vez usando listas
-	struct s_gnl	t_gnl;

	t_gnl.str = "s";
	printf("%s", t_gnl.str);
	fd = open("prueba/1.txt", O_RDONLY);
	str = get_next_line(t_gnl.fd);
	printf ("%s", t_gnl.str);
*/

/* el BUFFER_SIZE se utiliza para determinar el tamaño   */
