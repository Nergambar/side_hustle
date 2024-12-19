#include <stdio.h>
#include <unistd.h>
#include "get_next_line_sideft/get_next_line_bonus.h"

int	main()
{
	int		fd;
	char	*line;
	char	*save;

	fd = open("enemies.txt", O_RDWR | O_CREAT);
	if (fd == -1)
		return (printf("Problem creating file"));
	line = find_line(0, "[BEHOLDER]", "max_hp = ");
	if (!line)
	{
		//Continuo domaniiii
	}
	else
	{
		free(line);
		reset_fd(fd, "enemies.txt");
	}
}