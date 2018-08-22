/*
** EPITECH PROJECT, 2017
** epitech
** File description:
** flags_r_and_d
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include "my.h"

sort_t *my_rev_list(sort_t *list)
{
	sort_t *by;
	sort_t *sav;
	sort_t *rev;

	by = list;
	rev = NULL;
	while (by && by->next) {
		sav = by->next;
		by->next = rev;
		rev = by;
		by = sav;
	}
	by->next = rev;
	return (by);
}

void my_show_flag(sort_t *list)
{
	while (list) {
		my_printf("%s\n", list->name);
		list = list->next;
	}
}

sort_t *ls_flagr(int argc, char **argv, dir_t *compt)
{
	sort_t *list = NULL;

	if ((cdflags(argc, argv, compt) != 84 &&			\
	     ((compt->stat.st_mode & S_IFMT) == S_IFDIR)) || argc <= 2) {
		list = create_list(list, compt);
		my_sort_names(list);
		list = my_rev_list(list);
		my_show_list(list);
		closedir(compt->dir);
	} else
		my_printf("%s\n", argv[compt->a -1]);
	return (list);
}

sort_t *basefunctrev(dir_t *compt, int argc, char **argv)
{
	if (argc == 2)
		compt->a = 2;
	sort_t *list;
	if ((lstat(argv[compt->a], &compt->stat) != -1	\
	     && argc > 1) || argc <= 2) {
		list = ls_flagr(argc, argv, compt);
	} else
		(compt->a)++;
	if (compt->a != argc)
		list = basefunctrev(compt, argc, argv);
	return (list);
}

sort_t *dflag(dir_t *compt, int argc, sort_t *list, char **argv)
{
	while (compt->a != argc) {
		if (lstat(argv[compt->a], &compt->stat) != -1) {
			list = build_list(argv[compt->a], list);
			compt->b = 1;
		}
		(compt->a)++;
	}
	if (compt->b != 1)
		list = build_list(".", list);
	my_sort_names(list);
	return (list);
}
