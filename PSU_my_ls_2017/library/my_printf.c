/*
** EPITECH PROJECT, 2017
** epitech
** File description:
** my_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "myprint.h"

void difcase(va_list list, char character, int *i)
{
	switch (character) {
	case '%':
		my_putchar('%', i);
		break;
	case 's':
	       	my_putstr(va_arg(list, char *), i);
		break;
	case 'S':
		my_putstrmajs(va_arg(list, char *), i);
		break;
	case 'c':
		my_putchar(va_arg(list, int), i);
		break;
	case 'b':
		my_putptr((va_arg(list, int)), "01", i);
		break;
	case 'i':
	case 'd':
		my_put_nbr((va_arg(list, int)), i);
	}
}

int difcaseuns(va_list list, char character, int *i)
{
	switch (character) {
	case 'x':
		my_putnb_b((va_arg(list, unsigned int)), "0123456789abcdef", i);
		break;
	case 'X':
		my_putnb_b((va_arg(list, unsigned int)), "0123456789ABCDEF", i);
		break;
	case 'o':
		my_putnb_b((va_arg(list, unsigned int)), "01234567", i);
		break;
	case 'p':
		my_putstr("0x", i);
		my_putptr((va_arg(list, unsigned long)), "0123456789abcdef", i);
		break;
	case 'u':
		my_put_nbr_uns(va_arg(list, unsigned int), i);
		break;
	}
	return (0);
}

void difcasel(va_list list, char character, int *i)
{
	switch (character) {
	case 'x':
		my_putnb_b((long)va_arg(list, unsigned long),
			   "0123456789abcdef", i);
		break;
	case 'X':
		my_putnb_b((long)va_arg(list, unsigned long),
			   "0123456789ABCDEF", i);
		break;
	case 'o':
		my_putnb_b((long)va_arg(list, unsigned long), "01234567", i);
		break;
	case 'u':
		my_put_nbr_uns((long)va_arg(list, long), i);
		break;
	case 'd':
		my_put_nbr((long)va_arg(list, long), i);
		break;
	}
}

void difcasesecond(va_list list, char *s, int *i, int *a)
{
	switch (s[*a]) {
	case '#':
		if (s[*a + 1] == 'x')
			my_putstr("0x", i);
		else if (s[*a + 1] == 'X')
			my_putstr("0X", i);
		else if (s[*a + 1] == 'o')
			my_put_nbr(0, i);
		(*a)++;
		break;
	case '+':
		if (s[*a + 1] == 'd')
		 	my_putchar('+', i);
		(*a)++;
		break;
	case 'l':
		(*a)++;
		difcasel(list, s[*a], i);
		(*a)++;
	}
}

int my_printf(char *s, ...)
{
	va_list list;
	int i = 0;

	va_start(list, s);
	for (int a = 0; s[a] != '\0'; a++) {
		if (s[a] == '%') {
			a++;
			difcasesecond(list, s, &i, &a);
			difcase(list, s[a], &i);
			difcaseuns(list, s[a], &i);
		}
		else
			my_putchar(s[a], &i);
	}
	va_end(list);
	return (i);
}
