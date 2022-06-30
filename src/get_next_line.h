/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:src/include/get_next_line.h
/*   Created: 2022/06/28 23:06:53 by dugonzal          #+#    #+#             */
/*   Updated: 2022/06/28 23:23:48 by dugonzal         ###   ########.fr       */
=======
/*   Created: 2022/06/21 11:02:15 by ciclo-d           #+#    #+#             */
/*   Updated: 2022/06/30 09:35:04 by dugonzal         ###   ########.fr       */
>>>>>>> merge:src/get_next_line.h
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
<<<<<<< HEAD:src/include/get_next_line.h
=======
# define BUFFER_SIZE 8
>>>>>>> merge:src/get_next_line.h

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFFER_SIZE 6

char	*get_next_line(int fd);
<<<<<<< HEAD:src/include/get_next_line.h
=======
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *str, int c);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_slen(char *string, char c);
>>>>>>> merge:src/get_next_line.h

#endif
