/*
** EPITECH PROJECT, 2017
** nbr
** File description:
** nbr
*/

#include "my.h"

int my_put_nbr_uns(unsigned int nb, int *i)
{
	int mod;
	if (nb >= 4294967295) {
		return (84);
	}
	else if (nb >= 10) {
		mod = (nb % 10);
		nb = (nb - mod) / 10;
		my_put_nbr_uns(nb, i);
		my_putchar(48 + mod, i);
	}
	else
		my_putchar(48 + nb % 10, i);
	return (0);
}
