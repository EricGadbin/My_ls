/*
** EPITECH PROJECT, 2017
** ptr
** File description:
** printf
*/

#include <unistd.h>
#include "my.h"

int my_putptr(unsigned long nbr, char const *base, int *i)
{
	unsigned int modulo;
	int len = my_strlen(base);

	if (nbr == 0)
		my_putchar(48, i);
	modulo = nbr % len;
	nbr = (nbr - modulo) / len;
	if (nbr != 0) {
		my_putptr(nbr, base, i);
	}
	my_putchar(base[modulo], i);
	return (0);
}
