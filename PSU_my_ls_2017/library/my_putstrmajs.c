/*
** EPITECH PROJECT, 2017
** myputstr
** File description:
** task02
*/

#include "myprint.h"

void my_back(char const *str, int *e, int *i)
{
	if (str[*e] < 8) {
		my_putstr("\\00", i);
		my_putnb_b(str[*e], "01234567", i);
	}
	else if (str[*e] < 32) {
		my_putstr("\\0", i);
		my_putnb_b(str[*e], "01234567", i);
	}
	else if (str[*e] >= 127) {
		my_putstr("\\", i);
		my_putnb_b(str[*e], "01234567", i);
	}
}
int my_putstrmajs(char const *str, int *i)
{
	for (int e = 0; str[e] != '\0'; e += 1) {
		if (str[e] >= 127 || str[e] < 32)
			my_back(str, &e, i);
		else
			my_putchar(str[e], i);
	}
	return (0);
}
