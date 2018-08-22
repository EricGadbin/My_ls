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
#include <pwd.h>
#include <time.h>
#include <string.h>
#include "my.h"

char *my_strcat(char *path, sort_t *list)
{

	char *mal = malloc(sizeof(char) * my_strlen(path)	\
			   + my_strlen(list->name));
	int i = 0;
	int j = 0;

	while (i != my_strlen(path)) {
		mal[i] = path[i];
		i++;
	}
	while (j != my_strlen(list->name)) {
		mal[i] = list->name[j];
		i++;
		j++;
	}
	mal[i] = '\0';
	return (mal);
}

void my_show_list(sort_t *list)
{
	while (list) {
		if (list->name[0] != '.')
			my_printf("%s\n", list->name);
		list = list->next;
	}
}
