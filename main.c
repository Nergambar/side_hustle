
#include "gioco.h"

static void initall(all *this)
{
	this->p = (player *)calloc(sizeof(player), 1);
	this->p->job = (classes *)calloc(sizeof(classes), 1);

	this->p->name = (names *)calloc(sizeof(names), 1);
	this->p->name->last_name = malloc(sizeof(char) * 100);
	this->p->name->m_nicknames = malloc(sizeof(char) * 100);
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

int main()
{
	all		*this;
	size_t	size;
	int		fd = open("player_info.txt", O_RDWR);
	char	*s = get_next_line(fd);

	this = (all *)calloc(sizeof(all), 1);
	initall(this);
	names *name = this->p->name;
	if (!s)
		return(printf("aaaaaaaaaaaaa"), 0);
	if (strcmp(s, "") != 0)
	{
		if (strcmp(s, "Name: ") != 0)
			return (printf("fuck off"), 1);
		printf("Narrator: Welcome, uh.. fuck, what's your name again?");
		this->p->name->first_name = calloc(sizeof(char), 100);
		scanf("%99s", name->first_name);
		size = strlen(name->first_name) + 1;
		this->p->name->first_name = realloc(this->p->name->first_name, size);
		if (!write_in_file(name->first_name, fd, 0))
			printf("something went wrong!\n");
		printf("\nright, %s, finally you're here", name->first_name);
		printf("\n\n%zu", size);
		close(fd);
	}
	else
	{
		close(fd);
		open("player_info.txt", O_RDWR);
		name->first_name = get_that_line(fd, "Name: ");
		get_that_line(fd, "Name: ");
		if (!name->first_name)
			return (free(s), freeall(this), 1);
		printf("ah, %s, welcome back!\n", name->first_name);
	}
	;
	close(fd);
	freeall(this);
	return (0);
}