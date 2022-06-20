/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo-d <ciclo-d@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:38:10 by ciclo             #+#    #+#             */
/*   Updated: 2022/06/20 20:36:00 by ciclo-d          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h.h"

int	main(void)
{
	int		fd;
	int		bytes;
	//char *file;
	char *buffer;

	buffer = (char *)malloc(BUFFER_SIZE +1);
	if (!buffer)
		return (0);
	fd = open("fd.txt", O_RDONLY);
	bytes = read(fd, buffer, BUFFER_SIZE);
	printf ("%d", bytes);
	printf ("%s", buffer);
	free(buffer);
	close (fd);
}

/*
el read tiene 3 parametros el file descriptor,
el buffer ques es un puntero de char donde hacemos reserva de memoria con malloc,
y el BUFFER_SIZE  la cantidad que le pasamos por consola.
*/
