/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:02:15 by ciclo-d           #+#    #+#             */
/*   Updated: 2022/07/04 13:04:10 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 5

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

int		ft_count(char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *str, int c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
int		ft_slen(char *string, char c);
char	*ft_strdup(char *s1);
void	*ft_memmove(char *dest, char *src, size_t n);
char	*ft_linejoin(char *full);

#endif
