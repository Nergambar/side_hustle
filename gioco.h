/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gioco.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:58:13 by negambar          #+#    #+#             */
/*   Updated: 2024/12/10 17:48:16 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GIOCO_H
#define GIOCO_H

# include "struct.h"
# include <string.h>
#include "get_next_line.h"

int		write_in_file(char *s, int fd, int j);
int		check_N_write(char *s, char *s1, int fd);
char	*get_that_line(int fd, char *s);
char	*strtrim(char const *s1, char const *set);
char	*substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr1(const char *s, int c);

#endif