
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
	size_t ages = this->p->age;
	if (!s)
	{
		printf("Narrator: Welcome, uh.. fuck, what's your name again? ");
		this->p->name->first_name = calloc(sizeof(char), 100);
		scanf("%99s", name->first_name);
		size = strlen(name->first_name) + 1;
		this->p->name->first_name = realloc(this->p->name->first_name, size);
		char full[101];
		snprintf(full, sizeof(full), "Name: %s\n", name->first_name);
		if (!write_in_file(full, fd, 0))
			printf("something went wrong!\n");
		printf("\nright, %s, finally you're here", name->first_name);
		printf("\n\n%zu", size);
		printf("I'm sorry to ask, dear friend, but how old are you exactly? ");
		scanf("%zu", &ages);
		snprintf(full, sizeof(full), "Age: %zu\n", ages);
		if (!write_in_file(full, fd, 0))
			printf("something went wrong!\n");
		close(fd);
	}
	else
	{
		close(fd);
		open("player_info.txt", O_RDWR);
		name->first_name = get_that_line(fd, "Name: ", s);
		if (!name->first_name)
			return (free(s), freeall(this), 1);
		name->first_name = strtrim(name->first_name, "\n");
		printf("Ah, yes,%s, welcome back!\n", name->first_name);
	}
	close(fd);
	freeall(this);
	return (0);
}