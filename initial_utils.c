/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:12:01 by negambar          #+#    #+#             */
/*   Updated: 2024/12/09 17:32:27 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gioco.h"

int write_in_file(char *s, int fd)
{
	int i = 0;

	if (!fd)
		return 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
	return 1;
}

/* char **cnt_mtx(char *s, int fd, char **og)
{
	int i, j, tmp = 0;
	if (!og)
	{
		char **mtx = (char **)calloc(sizeof(char *), 10);
		mtx[1] = "Nome: \n";
		mtx[2] = "Eta: \n";
		mtx[3] = "Razza: \n";
		return (mtx);
	}
	else
	{
		while(og[j])
		{
			if (strncmp(s, "Nome:", 5))
			{
				tmp = j;
				free(og[j]);
				og[j] = (char *)calloc(sizeof(char) * 10);
				while (og[j])
				{
					og[j] = s[i];
					j++;
					i++;
				}
				write_in_file(s, fd);
				j = tmp;
			}
			if (strncmp(s, "Eta:", 4))
			{
				tmp = j;
				free(og[j]);
				og[j] = (char *)calloc(sizeof(char) * 10);
				while (og[j])
				{
					while (j <= 3)
					{
						
					}
					og[j] = s[i];
					j++;
					i++;
				}
				write_in_file(s, fd);
				j = tmp;
			}
			if (strncmp(s, "Razza:", 6))
			j++;
		}
	}
} */