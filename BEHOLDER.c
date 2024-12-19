#include <stdio.h>
#include <unistd.h>
#include "get_next_line_sideft/get_next_line_bonus.h"
#include "struct.h"
#define ERROR 1

int	initiate_enemy(int fd, char *name)
{
	int		counter;
	int		short_counter;
	int		long_counter;
	int		temp;
	char	*line;

	counter = MIDWORDS_LEN * 10;
	short_counter = MIDWORDS_LEN;
	long_counter = MIDWORDS_LEN * 60;
	temp = MIDWORDS_LEN * 10;
	line = find_line(MOVE, NULL);
	if (line)
		free(line);
	write(fd, '\n', 1);
	write(fd, name, strlen(name));
	write(fd, "\n\n", 2);
	write(fd, "name = ", 7);
	hold_space(counter, fd);
	write(fd, "age = ", 6);
	hold_space(short_counter, fd);
	write(fd, "honor = ", 8);
	hold_space(short_counter, fd);
	write(fd, "respect = ", 10);
	hold_space(short_counter, fd);
	write(fd, "job = ", 6);
	hold_space(counter, fd);
	write(fd, "race = ", 7);
	hold_space(counter, fd);
	write(fd, "class = ", 8);
	hold_space(counter, fd);
	write(fd, "alignment = ", 12);
	hold_space(short_counter, fd);
	write(fd, "_SHEET_\n", 8);
	write(fd, "strength = ", 7);
	hold_space(short_counter, fd);
	write(fd, "dexterity = ", 12);
	hold_space(short_counter, fd);
	write(fd, "constitution = ", 15);
	hold_space(short_counter, fd);
	write(fd, "intelligence = ", 15);
	hold_space(short_counter, fd);
	write(fd, "wisdom = ", 9);
	hold_space(short_counter, fd);
	write(fd, "charisma = ", 11);
	hold_space(short_counter, fd);
	write(fd, "proficiency = ", 14);
	hold_space(short_counter, fd);
	write(fd, "ispiration = ", 13);
	hold_space(short_counter, fd);
	write(fd, "speed = ", 8);
	hold_space(short_counter, fd);
	write(fd, "armour_class = ", 15);
	hold_space(short_counter, fd);
	write(fd, "initiative = ", 13);
	hold_space(short_counter, fd);
	write(fd, "max_hitpoints = ", 16);
	hold_space(short_counter, fd);
	write(fd, "current_hitpoints = ", 20);
	hold_space(short_counter, fd);
	write(fd, "attack_bonus = ", 15);
	hold_space(short_counter, fd);
	write(fd, "weapons = ", 10);
	hold_space(counter, fd);
	write(fd, "spell_list = ", 13);
	hold_space(long_counter, fd);
	write(fd, "_END_ENEMY]\n", 12);
	write(fd, "EOF\n", 4);
}

int	add_square_brackets(char **string)
{
	size_t	len;
	char	*save;

	if ((!string) || (!(*string)))
		return (ERROR);
	len = strlen(*string);
	save = *string;
	*string = calloc(len + 3, sizeof(char));
	if (!(*string))
	{
		free(save);
		return (ERROR);
	}
	(*string)[0] = '[';
	strcpy((*string) + 1, save);
	(*string)[len + 1] = ']';
	(*string)[len + 2] = 0;
	free(save);
	return (0);
}

int	gain_enemydata(random_encounter	**enemy, char *name)
{
	int		fd;
	char	*line;

	fd = open("enemies.txt", O_RDWR | O_CREAT);
	if (fd == -1)
		return (printf("Problem creating file"));
	if (!name)
		return (printf("Empty string as an argument!"));
	if (add_square_brackets(&name) == ERROR)
		return (printf("Malloc error add square brackets || NULL string taken"));
	line = find_line(FIND, "[thief_1]", "max_hp = ");
	if (!line)
	{
		if (initiate_enemy(fd, name) == ERROR)//todo
		{
			free(name);
			return (printf("Problem reading file!"));
		}
		reset_fd(fd, "enemies.txt");
		if (fill_enemy_struct() == ERROR)
		{
			free(name);
			freeall_enemy_struct();
			return (printf("malloc error in fill struct!"));
		}
	}
	else
	{
		free(line);
		reset_fd(fd, "enemies.txt");
		if (fill_struct() == ERROR)//todo
		{
			free(name);
			freeall_enemy_struct();
			return (printf("malloc error in fill struct!"));
		}
	}
	if (name)
		free(name);
	return (0);
}

int	main()
{
	random_encounter	*thief;

	thief = NULL;
	if (gain_enemydata(&thief, "thief_1") != 0)
		return (printf("\nBAD_ENDING :-("));
}