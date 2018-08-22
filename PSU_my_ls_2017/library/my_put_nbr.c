/*
** EPITECH PROJECT, 2017
** nbr
** File description:
** nbr
*/

#include "my.h"

int my_put_nbr(int nb, int *i)
{
	int mod;

	if (nb == -2147483648) {
		return (84);
	}
	if (nb < 0) {
		my_putchar('-', i);
		nb = nb * (-1);
	}
	if (nb >= 0) {
		if (nb >= 10) {
			mod = (nb % 10);
			nb = (nb - mod) / 10;
			my_put_nbr(nb, i);
			my_putchar((48 + mod), i);
		}
		else
			my_putchar((48 + nb % 10), i);
	}
	return (0);
}
