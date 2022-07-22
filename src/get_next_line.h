/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:02:15 by ciclo-d           #+#    #+#             */
/*   Updated: 2022/07/22 13:15:15 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 100000
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
//# include "../../libft/libft.h"

size_t	ft_strlen(char *str);
int		ft_count(char *str);
char	*get_next_line(int fd);
char	*ft_strchr(char *full, char c);
char	*ft_strjoin(char *full, char *buffer);
int		ft_slen(char *string, char c);

#endif
