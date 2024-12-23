/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gioco.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:58:13 by negambar          #+#    #+#             */
/*   Updated: 2024/12/19 15:13:36 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GIOCO_H
#define GIOCO_H

# include "struct.h"
# include <string.h>
# include <limits.h>
# include <signal.h>
# include "gnl.h"
# include "get_next_line_sideft/get_next_line_bonus.h"

int		write_in_file(char *s, int fd, int j);
char	*get_that_line(int fd, char *s, char *s1);
char	*strtrim(char const *s1, char const *set);
char	*substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr1(const char *s, int c);
void	reset(all *this, char *s);
char	*get_n_line(int fd, int n);
int		write_fucking_line(int fd, int line_num, int position, char *string);
int		reset_fd(int fd, char *name);
char	*find_line(int flag, ...);
void	initiate_file(int fd, char *num);
void	normalise_text(char *s);
int		second_step(all *this, int fd);
int		check_for_class(char *s);
void	and_so_the_story_starts(all *this,int fd, int a);
int		mi_serve(all *this);
void	freeall(all *this);
void	miservequesta(all *this, int fd);

#endif