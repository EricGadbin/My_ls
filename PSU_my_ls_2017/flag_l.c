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

int cdflags(int argc, char **argv, dir_t *compt)
{
	if (argc <= 1  || (argv[1][0] == '-' && argv[2] == NULL))
		compt->dir = opendir(".");
	else if (argc > 2) {
		compt->dir = opendir(argv[compt->a]);
		if (compt->dir && argc > 3)
			my_printf("%s:\n", argv[compt->a]);
		(compt->a)++;
	} else {
		compt->dir = opendir(argv[1]);
		(compt->a)++;
	}
	if (!compt->dir)
		return (84);
	return (0);
}

char *take_my_argv(char **argv, dir_t *compt, int argc, char *path)
{
	while (lstat(argv[compt->c + 1], &compt->stat) == -1) {
		compt->c++;
	}
	if (argc > 2 && argv[compt->c + 1][1] != '\0')
		path = argv[compt->c + 1];
	else if (argc > 2 && argv[compt->c + 1][0] == '/')
		path = argv[compt->c + 1];
	else
		path = "./";
	return (path);
}

void my_show_l(sort_t *list, dir_t *compt, char **argv, int argc)
{
	char *path;

	if (list->name[0] != '.' || list->next != NULL)
		my_total(compt, list);
	while (list) {
		if (list->name[0] != '.' || list->next == NULL) {
			path = take_my_argv(argv, compt, argc, path);
			path = my_strcat(path, list);
			lstat(path, &compt->stat);
			wrigth(compt);
			symbo(compt);
			my_printf("%s\n", list->name);
			free(path);
		}
		list = list->next;
	}
	compt->c += 1;
}

sort_t *ls_flagl(int argc, char **argv, dir_t *compt)
{
	sort_t *list = NULL;
	if ((cdflags(argc, argv, compt) != 84 && \
	((compt->stat.st_mode & S_IFMT) == S_IFDIR)) || argc <= 2) {
		list = create_list(list, compt);
		my_sort_names(list);
		my_show_l(list, compt, argv, argc);
		closedir(compt->dir);
	} else {
		list = build_list(argv[compt->a -1], list);
		my_show_l(list, compt, argv, argc);
	}
	return (list);
}

sort_t *baseforl(dir_t *compt, int argc, char **argv)
{
	sort_t *list = NULL;

	if (argc == 2)
		compt->a = 2;
	if ((stat(argv[compt->a], &compt->stat) != -1 && argc > 1	\
	     && (compt->stat.st_mode & S_IFMT) == S_IFDIR)  || argc <= 2)
		ls_flagl(argc, argv, compt);
	else if ((stat(argv[compt->a], &compt->stat) != -1 && argc > 1	\
		  && (compt->stat.st_mode & S_IFMT) != S_IFDIR)  || argc <= 2)
		ls_flagl(argc, argv, compt);
	else
		(compt->a)++;
	if (compt->a != argc)
		baseforl(compt, argc, argv);
	while (list != NULL) {
		free(list);
		list = list->next;
	}
	return (list);
}
