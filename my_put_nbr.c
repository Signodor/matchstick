/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** display number given as parameter
*/

#include "prototypes.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int recur_numb(int nb)
{
    if (nb > 9)
        recur_numb(nb / 10);
    my_putchar('0' + nb % 10);
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        nb = 147483648;
        recur_numb(nb);
    } else if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    recur_numb(nb);
    return (0);
}

int print_input(int mtch, int ln, int nb_l, int *tab)
{
    write(1, "Player removed ", 15);
    my_put_nbr(mtch);
    write(1, " match(es) from line ", 21);
    my_put_nbr(ln);
    write(1, "\n", 1);
    print_tab(nb_l, nb_l * 2 - 1, tab);
    return (0);
}