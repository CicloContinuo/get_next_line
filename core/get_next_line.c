/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:48:26 by dugonzal          #+#    #+#             */
/*   Updated: 2022/06/16 14:34:07 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

char	*get_next_line(int fd)
{
	char *temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!)
		return (NULL);
}

int	main(void)


}

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
