/*
** EPITECH PROJECT, 2017
** stlen
** File description:
** stlen
*/

int my_strlen(char const *str)
{
	int e = 0;

	while (str[e] != '\0') {
		e = e + 1;
	}
	return (e);
}
