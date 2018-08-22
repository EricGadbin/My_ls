/*
** EPITECH PROJECT, 2017
** epitech
** File description:
** sort
*/

#include <stdlib.h>
#include "my.h"

int is_it_sorted(sort_t *list)
{
	while (list->next) {
		if (my_strcmp(list->name, list->next->name) > 0)
			return (0);
		list = list->next;
	}
	return (1);
}

void my_sort_names(sort_t *list)
{
	sort_t *tmp = list;
	char *swapper;

	while (tmp->next) {
		if (my_strcmp(tmp->name, tmp->next->name) > 0) {
			swapper = tmp->name;
			tmp->name = tmp->next->name;
			tmp->next->name = swapper;
		}
		tmp = tmp->next;
		if (tmp->next == NULL && is_it_sorted(list) == 0)
			tmp = list;
	}
}
