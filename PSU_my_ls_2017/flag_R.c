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

void my_show_r(sort_t *list)
{
	while (list) {
		if (list->name[0] != '.')
			my_printf("%s\n", list->name);
		list = list->next;
	}
}

sort_t *ls_flagrmaj(int argc, char **argv, dir_t *compt)
{
	sort_t *list = NULL;
	if ((cdflags(argc, argv, compt) != 84 && \
	((compt->stat.st_mode & S_IFMT) == S_IFDIR)) || argc <= 2) {
		list = create_list(list, compt);
		my_sort_names(list);
		my_show_r(list);
		closedir(compt->dir);
	} else {
		list = build_list(argv[compt->a -1], list);
		my_show_r(list);
	}
	ls_flagrmaj(argc, argv, compt);
	return(list);
}

sort_t *baseforr(dir_t *compt, int argc, char **argv)
{
	if (argc == 2)
		compt->a = 2;
	sort_t *list = NULL;
	if ((stat(argv[compt->a], &compt->stat) != -1 && argc > 1
	&& (compt->stat.st_mode & S_IFMT) == S_IFDIR)  || argc <= 2)
		ls_flagr(argc, argv, compt);
	else if ((stat(argv[compt->a], &compt->stat) != -1 && argc > 1
	&& (compt->stat.st_mode & S_IFMT) != S_IFDIR)  || argc <= 2)
		ls_flagr(argc, argv, compt);
	 else
		(compt->a)++;
	if (compt->a != argc)
		baseforl(compt,argc, argv);
	while (list != NULL) {
		free(list);
		list = list->next;
	}
	return (list);
}
