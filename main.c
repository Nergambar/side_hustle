
#include "gioco.h"

static void initall(all *this)
{
	this->p = (player *)calloc(sizeof(player), 1);
	this->p->job = (classes *)calloc(sizeof(classes), 1);

	this->p->name = (names *)calloc(sizeof(names), 1);
	this->p->name->first_name = calloc(sizeof(char), 100);
	this->p->name->last_name = calloc(sizeof(char), 100);
	this->p->name->m_nicknames = calloc(sizeof(char), 100);
}

static void freeall(all *this)
{
	free(this->p->job);
	free(this->p->name->first_name);
	free(this->p->name->last_name);
	free(this->p->name->m_nicknames);
	free(this->p->name);
	free(this->p);
	free(this);
}

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

int main()
{
	all		*this;
	size_t	size;
	char	*new_line;
	int		fd = open("player_info.txt", O_RDWR);

	this = (all *)calloc(sizeof(all), 1);
	initall(this);
	names *name = this->p->name;
	new_line = get_next_line(fd);
	if (!new_line)
		return 1;
	if (strcmp(new_line, "VOID") == 0)
	{
		printf("Narrator: Welcome, uh.. fuck, what's your name again?");
		scanf("%99s", name->first_name);
		size = strlen(name->first_name) + 1;
		name->first_name = realloc(name->first_name, size);
		if (!write_in_file(name->first_name, fd))
			break;
		printf("\nright, %s, finally you're here", name->first_name);
		printf("\n\n%zu", size);
		// break ;
	}
	while ()
	close(fd);
	freeall(this);
	return (0);
}