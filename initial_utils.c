/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:12:01 by negambar          #+#    #+#             */
/*   Updated: 2024/12/10 16:09:02 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gioco.h"

int	write_in_file(char *s, int fd, int j)
{
	int i = 0;

	if (!fd)
		return 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	if (j == 1)
		write(fd, "\n", 1);
	return 1;
}

int	check_N_write(char *s, char *s1, int fd)
{
	char *str = get_next_line(fd);
	if (!fd)
		return (write(1,"{}",2), 0);
	else
	{
		if (str)
		while (strncmp(str, s1, strlen(s)) != 0)
		{
			str = get_next_line(fd);
			free(str);
		}
		printf("%s", str);
		if (strcmp(str, s) == 0)
			return (0);
		str = realloc(s, sizeof(char));
		size_t i = 0;
		while (i <= ft_strlen(str))
		{
			write_in_file(s1, fd, 0);
			write(fd, " ", 1);
			write_in_file(s, fd, 1);
		}
	}
	free(str);
	return (1);
}