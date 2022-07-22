/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:25:56 by ciclo             #+#    #+#             */
/*   Updated: 2022/07/22 12:36:22 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*s;
	int		fd;
	int		c;

	fd = open("txt/fd.txt", O_RDONLY);
	c = 2 ;
	while (c--)
	{
		s = get_next_line(fd);
		printf("{%s}\n", s);
		free (s);
	}
	close(fd);
	return (0);
}
