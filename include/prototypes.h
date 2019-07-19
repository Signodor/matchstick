/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** prototypes
*/

#ifndef PROTOTYPES_H_
    #define PROTOTYPES_H_

#include <unistd.h>
#include <stdlib.h>
#include "time.h"
int my_getnbr(char const *str);
void print_tab(int len_tab, int len, int *tab);
int *do_my_tab(int nb);
int how_many_sticks(int len_tab, int *tab, int len);
char *get_next_line(int fd);
int my_put_nbr(int nb);
void turn_of_ai(int *tab, int nb_l, int max_s);
int print_input(int mtch, int ln, int nb_l, int *tab);
int who_won(int nb_l, int *tab, int who);

#endif /* !PROTOTYPES_H_ */