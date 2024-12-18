/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:29:56 by negambar          #+#    #+#             */
/*   Updated: 2024/12/18 15:10:30 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gioco.h"

int	check_for_class(char *s)
{
	int	fd1 = open("classes.txt", O_RDONLY);
	// reset_fd(fd1, "classes.txt");
	char *str = get_next_line(fd1, 0);
	while (str && strncmp(str, s, strlen(s)) != 0)
	{
		free(str);
		str = get_next_line(fd1, 0);
	}
	if (!str)
		return (0);
	free(str);
	return (1);
}

int	second_step(all *this, int fd)
{
	int c;
	char *str = (char *)calloc(1, sizeof(char) * 100);

	printf("alright, let's get to it\n");
	usleep(500);
	system("clear");
	printf("alright, so...\nwhat class do you want?\n");
	while ((c = getchar()) != '\n' && c != EOF); // Clear the input buffer
	// fgets(str, 100, stdin);
	scanf("%99s", str);
	if (check_for_class(str))
	{
		this->p->class = str;
		size_t len = strlen(this->p->class);
		if (len > 0 && this->p->class[len - 1] == '\n')
			this->p->class[len - 1] = '\0';
		size_t size = strlen(this->p->class) + 1;
		this->p->class = realloc(this->p->class, size);
		reset_fd(fd, "player_info.txt");
		char *lns = find_line(FIND, fd, "Class = ", NULL);
		int n = atoi(lns);
		free(lns);
		reset_fd(fd, "player_info.txt");
		write_fucking_line(fd, n, 1, this->p->class);
		printf("\nnice choice!");
		return (1);
	}
	char *printf = "why not try a different one?\n";
	write(1, printf, strlen(printf));
	sleep(1);
	free(str);
	return (second_step(this, fd), 0);
}