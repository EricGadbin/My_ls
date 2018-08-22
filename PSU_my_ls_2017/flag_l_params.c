/*
** EPITECH PROJECT, 2017
** epitech
** File description:
** ls
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <string.h>
#include "my.h"

void wrigth(dir_t *compt)
{
	my_printf("%c", S_ISDIR(compt->stat.st_mode) ? 'd' : '-');
	my_printf("%c", (compt->stat.st_mode & S_IRUSR) ? 'r' : '-');
	my_printf("%c", (compt->stat.st_mode & S_IWUSR) ? 'w' : '-');
	my_printf("%c", (compt->stat.st_mode & S_IXUSR) ? 'x' : '-');
	my_printf("%c", (compt->stat.st_mode & S_IRGRP) ? 'r' : '-');
	my_printf("%c", (compt->stat.st_mode & S_IWGRP) ? 'w' : '-');
	my_printf("%c", (compt->stat.st_mode & S_IXGRP) ? 'x' : '-');
	my_printf("%c", (compt->stat.st_mode & S_IROTH) ? 'r' : '-');
	my_printf("%c", (compt->stat.st_mode & S_IWOTH) ? 'w' : '-');
	my_printf("%c%c", (compt->stat.st_mode & S_IXOTH) ? 'x' : '-', ' ');

}

char *user(dir_t *compt)
{
	struct passwd *p;
	p = getpwuid(compt->stat.st_uid);
	return (p->pw_name);
}

char *group(dir_t *compt)
{
	struct passwd *p;

	p = getpwuid(compt->stat.st_gid);
	return (p->pw_name);
}

void symbo(dir_t *compt)
{
	char *date;

	date = ctime(&compt->stat.st_mtime);
	date += 4;
	date[12] = '\0';
	my_printf("%d%c%s%c", compt->stat.st_nlink, '	', user(compt), ' ');
	my_printf("%s %d %s ", group(compt), compt->stat.st_size, date);
}

void my_total(dir_t *compt, sort_t *list)
{
	int total = 0;
	while (list) {
		if (list->name[0] != '.') {
			stat(list->name, &compt->stat);
			total += compt->stat.st_blocks / 2;
		}
		list = list->next;
	}
	my_printf("total %d\n", total);
}
