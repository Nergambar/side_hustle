/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gioco.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:58:13 by negambar          #+#    #+#             */
/*   Updated: 2024/12/10 16:06:43 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GIOCO_H
#define GIOCO_H

# include "struct.h"
# include <string.h>
#include "get_next_line.h"

int	write_in_file(char *s, int fd, int j);
int	check_N_write(char *s, char *s1, int fd);

#endif