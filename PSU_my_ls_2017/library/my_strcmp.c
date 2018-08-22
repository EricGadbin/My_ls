/*
** EPITECH PROJECT, 2017
** epitech
** File description:
** cmp
*/

#include <stdio.h>

int theif (char part1, char part2)
{
	int a = 0;
	int b = 0;

	if (part1 >= 'A' && part1 <= 'Z')
		a = 32;
	if (part2 >= 'A' && part2 <= 'Z')
		b = 32;
	if (part1 + a != part2 + b)
		return ((part1 + a) - (part2 + b));
	return (0);
}

int my_strcmp (char *list1, char *list2)
{
	int i = 0;
	int j = 0;

	while (list1[j] != '\0') {
		if (!(list1[j] >= '0' && list1[j] <= '9') && !(list1[j] >= 'A' \
		&& list1[j] <= 'Z') && !(list1[j] >= 'a' && list1[j] <= 'z')) {
			j++;
		}
		if (!(list2[i] >= '0' && list2[i] <= '9' )&& !(list2[i] >= 'A' \
		&& list2[i] <= 'Z') && !(list2[i] >= 'a' && list2[i] <= 'z')) {
			i++;
		}
		if (theif (list1[j], list2[i]) !=  0)
			return (theif (list1[j], list2[i]));
		i++;
		j++;
	}
	if (list2[i] != '\0')
		return (list1[j] - list2[i]);
	return (0);
}
