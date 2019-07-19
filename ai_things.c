/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** ai_things
*/

#include "prototypes.h"

int choose_line(int *tab, int ln, int max_s, int nb_l)
{
    int len = 0;
    int ret = 0;

    while (tab[len] != -1)
        len++;
    if (len == 1) {
        for (int i = 0; i < tab[ln] && i < max_s; i++)
            ret = tab[ln] - i == (max_s + 1) + 1 ? i : 1;
        return (ret);
    }
    if (how_many_sticks(nb_l, tab, nb_l * 2 - 1) <= max_s + 1 &&
    tab[ln] <= max_s + 1)
        return (tab[ln] - 1 > 0 ? tab[ln] - 1 : 1);
    if (tab[ln] < max_s)
        return (rand() % tab[ln] + 1);
    else
        return (rand() % max_s + 1);
}

int who_won(int nb_l, int *tab, int who)
{
    if (who == 2) {
        write(1, "You lost, too bad...\n", 21);
        return (2);
    }
    write(1, "I lost... snif... but I'll get you next time!!\n", 47);
    return (1);
}

int *fill_ln(int *tab, int nb_l)
{
    int *ret = NULL;
    int len = 0;
    int j = 0;

    for (int i = 0; i < nb_l; i++)
        len += tab[i] > 0;
    ret = malloc(sizeof(int) * (len + 1));
    for (int i = 0; i < nb_l; i++)
        if (tab[i] > 0) {
            ret[j] = i;
            j++;
        }
    ret[len] = -1;
    return (ret);
}

void print_res(int *tab, int nb_l, int mtch, int ln)
{
    write(1, "\nAI's turn...\n", 14);
    write(1, "AI removed ", 11);
    my_put_nbr(mtch);
    write(1, " match(es) from line ", 21);
    my_put_nbr(ln + 1);
    write(1, "\n", 1);
    print_tab(nb_l, nb_l * 2 - 1, tab);
}

void turn_of_ai(int *tab, int nb_l, int max_s)
{
    int ln;
    int mtch;
    int *how_filled_ln = fill_ln(tab, nb_l);
    int len = 0;
    int res = 0;

    while (how_filled_ln[len] != -1)
        len++;
    srand(time(NULL));
    ln = how_filled_ln[rand() % len];
    mtch = choose_line(tab, ln, max_s, nb_l);
    if (len == 2)
        for (int i = 0; i < len; i++)
            res += tab[how_filled_ln[i]] == 1 ? 1 : 0;
    if (res) {
        for (int i = 0; i < len; i++)
            ln = tab[how_filled_ln[i]] > tab[ln] ? how_filled_ln[i] : ln;
        mtch = tab[ln] <= max_s ? tab[ln] : mtch;
    }
    tab[ln] -= mtch;
    print_res(tab, nb_l, mtch, ln);
}