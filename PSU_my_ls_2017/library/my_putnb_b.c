/*
** EPITECH PROJECT, 2017
** my_putnbrbase
** File description:
** base
*/

#include <unistd.h>
#include "my.h"

int my_putnb_b(unsigned int nbr, char const *base, int *i)
{
	unsigned int modulo;
	int len = my_strlen(base);

	if (nbr == 0)
		my_putchar(48, i);
	modulo = nbr % len;
	nbr = (nbr - modulo) / len;
	if (nbr != 0) {
		my_putnb_b(nbr, base, i);
	}
	my_putchar((base[modulo]), i);
	return (0);
}
