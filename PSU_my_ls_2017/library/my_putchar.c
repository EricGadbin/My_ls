/*
** EPITECH PROJECT, 2017
** char
** File description:
** put
*/

#include <unistd.h>

void my_putchar(char c, int *i)
{
	(*i)++;
	write(1, &c, 1);
}
