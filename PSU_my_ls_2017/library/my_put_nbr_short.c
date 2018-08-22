/*
** EPITECH PROJECT, 2017
** nbr
** File description:
** nbr
*/

#include "my.h"

int my_put_nbr_short(short int nb, int *i)
{
	short mod;
	if (nb == -32768) {
		my_put_nbr_short(nb, i);
		return (0);
	}
	if (nb < 0) {
		my_putchar('-', i);
		nb = nb * (-1);
	}
	if (nb >= 0) {
		if (nb >= 10) {
			mod = (nb % 10);
			nb = (nb - mod) / 10;
			my_put_nbr_short(nb, i);
			my_putchar(48 + mod, i);
		}
		else
			my_putchar(48 + nb % 10, i);
	}
	return (0);
}
