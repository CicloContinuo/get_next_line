/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:25:56 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/12 19:40:57 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*s;
	int		fd;
	int		c;
	(void)argc;
	fd = open(argv[1], O_RDONLY);
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
