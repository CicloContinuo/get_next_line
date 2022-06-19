/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:49:03 by ciclo             #+#    #+#             */
/*   Updated: 2022/06/17 13:22:11 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

/*int	main(void)
{
	//const char	*s;
	int	fd;

	fd = open("fd/0.txt", O_WRONLY, O_APPEND);
	//s = read (fd, 3);
	return (0);
}
*/

int	main(void)
{
	int	filedesc;

	filedesc = open("fd/0.txt", O_WRONLY | O_APPEND);
	printf ("%d", filedesc);
	return (0);
}
