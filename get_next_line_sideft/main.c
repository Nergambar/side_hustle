/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:41:41 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/18 18:20:18 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line_bonus.h"
# include "../gioco.h"

char	*get_n_line(int fd, int n);
int		write_fucking_line(int fd, int line_num, int position, char *string);
int		reset_fd(int fd, char *name);
char	*find_line(int flag, ...);
void	initiate_file(int fd, char *num);

static void hold_space(int counter, int fd)
{
	while (counter--)
		write(fd, " ", 1);
	write(fd, "\n", 1);
}
void	initiate_file(int fd, char *name)
{
	int	counter;
	int	temp;
	
	counter = MIDWORDS_LEN * 10;
	temp = MIDWORDS_LEN * 10;
	write(fd, "[PLAYER_", 8);
	write(fd, name, strlen(name));
	free(name);
	write(fd, "]", 1);
	write(fd, "\n\n", 2);
	write(fd, "Name = ", 7);
	hold_space(counter, fd);
	write(fd, "Age = ", 7);
	hold_space(counter, fd);
	write(fd, "Class = ", 8);
	hold_space(counter, fd);
	write(fd, "Species = ", 11);
	hold_space(counter, fd);
	write(fd, "Friends = ", 10);
	hold_space(counter, fd);
	write(fd, "_ENDPLAYER_1]\n", 14);
	write(fd, "EOF\n", 4);
}

int		write_fucking_line(int fd, int line_num, int position, char *string)
{
	char	buffer[1];
	int		counter;
	char	*temp;

	if ((fd == -1) || (!string))
		return (-1);
	temp = get_n_line(fd, line_num - 1);
	if (!temp)
		return (-1);
	free(temp);
	if (read(fd, buffer, 1) <= 0)
		return (-1);
	while ((buffer[0] != ' ') && (buffer[0] != '\n') && (buffer[0] != '\0'))
	{
		if (read(fd, buffer, 1) <= 0)
			return (-1);
	}
	if ((buffer[0] == '\n') || (buffer[0] == '\0'))
		return (-1);
	while ((position--))
	{
		if (read(fd, buffer, 1) <= 0)
			return (-1);
		while ((buffer[0] != ' ') && (buffer[0] != '\n') && (buffer[0] != '\0'))
		{
			if (read(fd, buffer, 1) <= 0)
				return (-1);
		}
		if ((buffer[0] == '\n') || (buffer[0] == '\0'))
			return (-1);
	}
	counter = 0;
	while (counter != MIDWORDS_LEN)
	{
		if (*string)
		{
			write(fd, string, 1);
			string++;
		}
		else
			write(fd, "_", 1);
		++counter;
	}
	write (fd, ", ", 1);
	while ((buffer[0] == '\n') || (buffer[0] == '\0'))
	{
		if (read(fd, buffer, 1) <= 0)
			return (-1);
	}
	return (line_num);
}

/*
Flags list
Find = 0 ---> finds where a line is located in a file text (in a string format)
Get  = 1 ---> Finds and give back the content of a line
Move = 2 ---> Moves the cursor to the line

Example:
find_line(GET, "[BEHOLDER]", "max_hp = ")

In this way, find_line finds before the line "[BEHOLDER]", then "max_hp".
If it finds both, it return the line of the last content, else return NULL.
*/
char	*find_line(int flag, ...)
{
	va_list	list;
	char	*string;
	char	*search;
	int		fd;
	int		counter;

	va_start(list, flag);
	fd = (int)va_arg(list, int);
	counter = 1;
	string = get_next_line(fd, 0);
	if (!string)
	{
		va_end(list);
		return (NULL);
	}
	search = va_arg(list, char *);
	while ((search) && (string))
	{
		while (strstr(string, search) == NULL)
		{
			free(string);
			string = get_next_line(fd, 0);
			if (!string)
				break ;
			++counter;
		}
		search = va_arg(list, char *);
	}
	va_end(list);
	if (!string)
		return (NULL);
	free(string);
	if (flag == FIND)
		return (ft_itoa(counter));
	if (flag == GET)
		return (get_n_line(fd, counter));
	if (flag == MOVE)
		return (get_n_line(fd, counter - 1));
	return ("Metti le flag ammodo, mongoloide");
}

char	*get_n_line(int fd, int n)
{
	char	*line;

	line = NULL;
	while (n--)
	{
		if (line)
			free(line);
		line = get_next_line(fd, 0);
		if (!line)
			break ;
	}
	return (line);
}

int	reset_fd(int fd, char *name)
{
	get_next_line(fd, RESET);
	close(fd);
	fd = open(name, O_RDWR);
	return (0);
}

/* int	main()
{
	char	*string;
	int		fd;
	int		counter;
	int		line_num;

	counter = 5;
	fd = open("updated_pokedex.txt", O_RDWR);
	if (fd == -1)
		return (1);
	while (counter--)
	{
		string = get_next_line(fd, 0);
		//printf("%s", string);
		if (string)
		{
			free(string);
		}
		else
			break ;
	}
	reset_fd(fd, "updated_pokedex.txt");
	string = find_line(FIND, 3, "CHARMANDER", "Weight", NULL);
	printf("%s\n", string);
	line_num = atoi(string);
	free(string);
	string = get_next_line(fd, 0);
	printf("%s\n", string);
	//printf("%s", string);
	free(string);
	write_fucking_line(fd, line_num, 1, "777");
	fd = open("dati_personaggio.txt", O_RDWR);
	if (fd == -1)
	{
		fd = open("dati_personaggio.txt", O_RDWR | O_CREAT);
		if (fd == -1)
			return (1);
		initiate_file(fd, ft_itoa(1));
	}
	reset_fd(fd, "dati_personaggio.txt");
	string = find_line(FIND, fd, "PLAYER_1", "Name", NULL);
	line_num = atoi(string);
	free(string);
	reset_fd(fd, "dati_personaggio.txt");
	write_fucking_line(fd, line_num++, 1, "Marco");
	reset_fd(fd, "dati_personaggio.txt");
	write_fucking_line(fd, line_num++, 1, "27");
	reset_fd(fd, "dati_personaggio.txt");
	write_fucking_line(fd, line_num++, 1, "Bard");
	reset_fd(fd, "dati_personaggio.txt");
	write_fucking_line(fd, line_num, 1, "Gino");
	reset_fd(fd, "dati_personaggio.txt");
	write_fucking_line(fd, line_num, 2, "Beppe");
	reset_fd(fd, "dati_personaggio.txt");
	write_fucking_line(fd, line_num, 1, "Marco");
	return (0);
}
 */