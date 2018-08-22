/*
** EPITECH PROJECT, 2017
** epitech
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include "my.h"

int main(int argc, char **argv)
{
	dir_t compt;
	struct stat s;

	compt.a = 1;
	if (flags(argc, argv, &compt) == 0)
		basefunct(&compt, argc, argv, &s);
	return (0);
}
