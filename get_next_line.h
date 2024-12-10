/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:43:14 by negambar          #+#    #+#             */
/*   Updated: 2023/12/14 11:50:50 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(char *s);
char	*ft_substr(char const *s, unsigned int start, char stop_char);
char	*ft_calloc(size_t count, size_t size);
char	*ft_get_line(int fd, char *buffer, char *nextl);
char	*get_next_line(int fd);
char	*ft_str(char *s);

#endif