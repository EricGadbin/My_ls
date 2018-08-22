/*
** EPITECH PROJECT, 2017
** epitech
** File description:
** myls
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include "my.h"

sort_t *build_list (char *d_name, sort_t *list)
{
	sort_t *new = malloc(sizeof (sort_t));

	new->name = d_name;
	new->next = list;
	return (new);
}

int cd(int argc, char **argv, dir_t *compt)
{
	if (argc <= 1  || (argv[1][0] == '-' && argv[2] == NULL))
		compt->dir = opendir(".");
	else if (argc > 2) {
		compt->dir = opendir(argv[compt->a]);
		if (compt->dir && argc > 2)
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

sort_t *create_list(sort_t *list, dir_t *compt)
{
	int i = 0;
	struct dirent *folder;
	while ((folder = readdir(compt->dir)) != NULL) {
		list = build_list(folder->d_name, list);
		i++;
	}
	return (list);
}

sort_t *ls_no_flags(struct stat *s, int argc, char **argv, dir_t *compt)
{
	sort_t *list = NULL;

	if ((cd(argc, argv, compt) != 84 && \
	((s->st_mode & S_IFMT) == S_IFDIR)) || argc <= 1) {
		list = create_list(list, compt);
		my_sort_names(list);
		my_show_list(list);
		closedir(compt->dir);
	} else
	my_printf("%s\n", argv[compt->a -1]);
	return (list);
}

int basefunct(dir_t *compt, int argc, char **argv, struct stat *s)
{
	sort_t *list;
	if ((lstat(argv[compt->a], s) != -1 && argc > 1) || argc <= 1) {
		list = ls_no_flags(s, argc, argv, compt);
	} else
		(compt->a)++;
	if (compt->a != argc)
		basefunct(compt, argc, argv, s);
	while (list != NULL) {
		free(list);
		list = list->next;
	}
	return (0);
}
