/*
** EPITECH PROJECT, 2017
** epitech
** File description:
** my
*/

#include <sys/stat.h>
#include <dirent.h>
#ifndef MY_H_
#define MY_H_

typedef struct sort_s {
	char *name;
	struct sort_s *next;
} sort_t;

typedef struct dir_s {
	DIR *dir;
	int a;
	int b;
	int c;
	struct stat stat;
}dir_t;

void my_putchar(char, int *);
int my_put_nbr(int, int *);
int my_put_nbr_short(short int, int *);
int my_putstr(char const *, int *);
int my_strlen(char const *);
int my_putstrmajs(char const *, int *);
int my_putptr(unsigned long, char const *, int *);
int my_putnb_b(unsigned int, char const *, int *);
int my_put_nbr_uns(unsigned int, int *);
int my_strcmp(char *, char *);
int my_printf(char *, ...);
int is_it_sorted(sort_t *);
void my_sort_names(sort_t *);
sort_t *build_list (char *, sort_t *);
int basefunct(dir_t *, int, char **, struct stat *);
int flags(int, char **, dir_t *);
sort_t *ls_no_flags(struct stat *, int, char **, dir_t*);
sort_t *create_list(sort_t *, dir_t *);
void my_show_list(sort_t *);
int cd(int, char **, dir_t *);
sort_t *my_rev_list(sort_t *);
void my_show_flag(sort_t *);
sort_t *ls_flagr(int, char **, dir_t *);
sort_t *basefunctrev(dir_t *, int, char **);
sort_t *dflag(dir_t *, int, sort_t *, char **);
sort_t *baseforl(dir_t *, int, char **);
int cdflags(int, char **, dir_t *);
sort_t *baseforr(dir_t *, int, char **);
void wrigth(dir_t *);
char *group(dir_t *);
void symbo(dir_t *);
char *user(dir_t *);
void my_total(dir_t *, sort_t *);
char *my_strcat(char *, sort_t *);

#endif /* MY_H_ */
