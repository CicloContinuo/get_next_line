/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:49:03 by ciclo             #+#    #+#             */
/*   Updated: 2022/06/17 09:11:44 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

int	main(void)
{
	char	*string;
	int fd = open("fd/0.txt", O_RDONLY);
	ssize_t i = read (fd, BUFFER_SIZE);
	return (0);
}
