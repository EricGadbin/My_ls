/*
** EPITECH PROJECT, 2017
** myputstr
** File description:
** task02
*/

#include "my.h"

int my_putstr(char const *str, int *i)
{
	int e = 0;

	while (str[e] != '\0') {
		my_putchar(str[e], i);
		e = e + 1;
	}
	return (0);
}
