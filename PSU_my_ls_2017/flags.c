/*
** EPITECH PROJECT, 2017
** epitech
** File description:
** flags
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include "my.h"

int putflagsnext(char *flag, int argc, char **argv, dir_t *compt)
{
	if (flag[2] == 1 && flag[0] == 48)
		baseforl(compt, argc, argv);
	if (flag[3] == 1)
		baseforr(compt, argc, argv);
	return (0);
}

int putflags(char *flag, int argc, char **argv, dir_t *compt)
{
	sort_t *list = NULL;
	int d = 0;

	if (flag[0] == 1)
		list = dflag(compt, argc, list, argv);
	if (flag[1] == 1 && flag[0] == 1) {
		list = my_rev_list(list);
	}
	else if (flag[1] == 1 && flag[0] == 48 && flag[2] == 48) {
		basefunctrev(compt, argc, argv);
		d = 1;
	}
	putflagsnext(flag, argc, argv, compt);
	if (d != 1)
		my_show_flag(list);
	while (list != NULL) {
		free(list);
		list = list->next;
	}
	return (0);
}

int  difflag(char *add , char *flag)
{
	while (*add != '\0') {
		switch (*add) {
		case 'd':
			flag[0] = 1;
			break;
		case 'r':
			flag[1] = 1;
			break;
		case 'l':
			flag[2] = 1;
			break;
		case 'R':
			flag[3] = 1;
			break;
		}
		add++;
	}
	return (1);
}

char *mallocofflag(void)
{
	int c = 0;
	char *flag = malloc(sizeof(char) * 5);

	while (flag[c] < 5) {
		flag[c] = '0';
		c++;
	}
	flag[c] = '\0';
	return (flag);

}

int flags(int argc, char **argv, dir_t *compt)
{
	int b = 0;
	int i = 1;
	int j = 0;

	char *flag = mallocofflag();
	while (i != argc) {
		if (argv[i][j] == '-')
			b = difflag(argv[i] + 1, flag);
		if (argv[i][j] == '\0') {
			j++;
			i = 0;
		}
	i++;
	}
	if (b == 1) {
		putflags(flag, argc, argv, compt);
		return (1);
	}
	free(flag);
	return (0);
}
