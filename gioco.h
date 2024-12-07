/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gioco.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:14:09 by negambar          #+#    #+#             */
/*   Updated: 2024/12/07 16:27:54 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GIOCO_H
# define GIOCO_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_dice
{
	int		faces:5;
}	t_dice;

typedef struct s_classes
{
	unsigned int	classes:4;
} classes;

typedef struct s_names
{
	char	*first_name;
	char	*m_nicknames;
	char	*last_name;
}	names;

typedef struct s_player
{
	names			name; //struct?
	size_t			age;
	t_dice			dice;
	int				honor; // estremi +-100
	char			**status;
	unsigned int	respect;	
	classes			job; //16 classi
	unsigned int	races:1; // 2 razze iniziale
	int				allignment:3;
}	player;

#endif