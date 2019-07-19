/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** about_tab
*/

#include "prototypes.h"

int how_many_sticks(int len_tab, int *tab, int len)
{
    int res = 0;

    for (int i = 0; i < len_tab; i++)
        res += tab[i];
    return (res);
}

void print_tab(int len_tab, int len, int *tab)
{
    for (int i = 0; i < len + 2; i++)
        write(1, "*", 1);
    write(1, "\n", 1);
    for (int i = 0; i < len_tab; i++) {
            write(1, "*", 1);
        for (int j = 0; j < len_tab - i - 1; j++)
            write(1, " ", 1);
        for (int j = 0; j < tab[i]; j++)
            write(1, "|", 1);
        for (int j = len_tab - i + tab[i] - 1; j < len; j++)
            write(1, " ", 1);
        write(1, "*\n", 2);
    }
    for (int i = 0; i < len + 2; i++)
        write(1, "*", 1);
    write(1, "\n", 1);
}

int *do_my_tab(int nb)
{
    int *tab = malloc(sizeof(int) * nb);

    for (int i = 0; i < nb; i++)
        tab[i] = 1 + 2 * i;
    return (tab);
}