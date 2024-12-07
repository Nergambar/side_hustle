/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gioco.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:14:09 by negambar          #+#    #+#             */
/*   Updated: 2024/12/07 15:28:55 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GIOCO_H
# define GIOCO_H

typedef struct s_player
{
	char	*name; //struct?
	int		age;
	int		classes:4; //16 classi
	int		races:1; // 2 razze iniziale
}	player;

#endif