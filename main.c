#include "gioco.h"

void reset(all *this, char *s);

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

static void clear_stdin(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

static void set_basics(all *this, int fd, int i)
{
	printf("Narrator: Welcome, uh.. what's your name again? ");
	this->p->name->first_name = calloc(100, sizeof(char));
	if (i == 1)
		clear_stdin();
	fgets(this->p->name->first_name, INT_MAX -1, stdin);
	size_t len = strlen(this->p->name->first_name);
	if (len > 0 && this->p->name->first_name[len - 1] == '\n')
		this->p->name->first_name[len - 1] = '\0';
	size_t size = strlen(this->p->name->first_name) + 1;
	this->p->name->first_name = realloc(this->p->name->first_name, size);
	char full[101];
	snprintf(full, sizeof(full), "Name: %s\n", this->p->name->first_name);
	printf("%s", this->p->name->first_name);
	if (!write_in_file(full, fd, 0))
		printf("something went wrong!\n");
	printf("\nright, %s, finally you're here\n", this->p->name->first_name);
	printf("I'm sorry to ask, dear friend, but how old are you exactly? ");
	scanf("%zu", &this->p->age);
	if (i == 1)
		clear_stdin();
	snprintf(full, sizeof(full), "Age: %zu\n", this->p->age);
	if (this->p->age <= 17)
	{
		printf("I'm sorry little one, you aren't who I thought you were.\
Come back when you're older.\n\n\n\n\n");
		reset(this, NULL);
		return ;
	}
	if (!write_in_file(full, fd, 0))
		printf("something went wrong!\n");
	close(fd);
}

void reset(all *this, char *s)
{
	int fd = open("player_info.txt", O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("Failed to reset file");
		if (s)
			free(s);
		freeall(this);
		return;
	}
	set_basics(this, fd, 1);
}

int main(int ac, char **av)
{
	all		*this;
	int		fd = open("player_info.txt", O_RDWR);
	char	*s = get_next_line(fd);
	char	full[101];

	this = (all *)calloc(sizeof(all), 1);
	initall(this);
	names *name = this->p->name;
	if (!s)
		set_basics(this, fd, 0);
	else if (s && ac == 1)
	{
		name->first_name = get_that_line(fd, "Name: ", s);
		if (!name->first_name)
			return (free(s), freeall(this), 1);
		name->first_name = strtrim(name->first_name, "\n");
		printf("Ah, yes,%s, welcome back!\n", name->first_name);
	}
	else if (ac == 2 && strcmp(av[1], "reset") == 0)
		reset(this, s);
	else if (ac == 2 && strcmp(av[1], "change_name") == 0)
    {
        char *age_line = NULL;
        while ((s = get_next_line(fd)) != NULL && strncmp(s, "Age:", 4) != 0)
            free(s);
		if (strncmp(s, "Age:", 4) == 0)
			age_line = strdup(s);
        close(fd);
        fd = open("player_info.txt", O_RDWR | O_TRUNC);
        printf("I understand, how would you like to be called then?\n");
        fgets(this->p->name->first_name, 100, stdin);
        size_t len = strlen(this->p->name->first_name);
        if (len > 0 && this->p->name->first_name[len - 1] == '\n')
            this->p->name->first_name[len - 1] = '\0';
        size_t size = strlen(this->p->name->first_name) + 1;
        this->p->name->first_name = realloc(this->p->name->first_name, size);
        snprintf(full, sizeof(full), "Name: %s\n", this->p->name->first_name);
        printf("%s", this->p->name->first_name);
        if (!write_in_file(full, fd, 0))
            printf("something went wrong!\n");
        if (age_line)
        {
            write_in_file(age_line, fd, 0);
            free(age_line);
        }
    }
	close(fd);
	freeall(this);
	return (0);
}
