/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:38:10 by ciclo             #+#    #+#             */
/*   Updated: 2022/06/17 13:59:32 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h.h"

char	*ft_read(int filedesc)
{
	char	*buffer;
	int		read_file;

	buffer = (char *)malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_file = read (filedesc, buffer, BUFFER_SIZE);
	return (buffer);
}

int	main(void)
{
	int	filedesc;

	filedesc = open ("../../txt/0.txt", O_WRONLY, O_APPEND);
	static char str = ft_read(filedesc);
	printf ("%s", str);
}

/*
el read tiene 3 parametros el file descriptor,
el buffer ques es un puntero de char donde hacemos reserva de memoria con malloc,
y el BUFFER_SIZE  la cantidad que le pasamos por consola.
*/
