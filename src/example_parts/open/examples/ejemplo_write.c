/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejemplo_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:10:36 by ciclo             #+#    #+#             */
/*   Updated: 2022/06/17 11:42:39 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h.h"

int	main(void)
{
	int	filedesc;

	filedesc = open("testfile.txt", O_WRONLY | O_APPEND);
	if (filedesc < 0)
		write(2,"There was an e\n");
	 // strictly not an error, it is allowable for fewer characters
	// than requested to be written.
	return (0);
}
