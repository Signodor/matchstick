/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** main
*/

#include "prototypes.h"

int check_error_input_mtch(int input, int nb, int nb_l, int *tab)
{
    if (input > nb) {
        write(1, "Error: you cannot remove more than ", 35);
        my_put_nbr(nb);
        write(1, " matches per turn\n", 18);
        return (84);
    }
    if (input == 0) {
        write(1, "Error: you have to remove at least one match\n", 45);
        return (84);
    }
    if (input < 0) {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (84);
    }
    if (input > tab[nb_l - 1]) {
        write(1, "Error: not enough matches on this line\n", 39);
        return (84);
    }
    return (0);
}

int check_error_input_ln(int input, int nb, int *tab)
{
    if (input < 0) {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (84);
    }
    if (input > nb || input == 0) {
        write(1, "Error: this line is out of range\n", 33);
        return (84);
    }
    return (0);
}

int check_input(int nb_l, int max_s, int *tab)
{
    int ln;
    int mtch;
    char *buff;

    write(1, "Line: ", 6);
    buff = get_next_line(0);
    if (buff == NULL)
        return (-1);
    ln = my_getnbr(buff);
    if (check_error_input_ln(ln, nb_l, tab) == 84)
        return (84);
    write(1, "Matches: ", 9);
    buff = get_next_line(0);
    if (buff == NULL)
        return (-1);
    mtch = my_getnbr(buff);
    if (check_error_input_mtch(mtch, max_s, ln, tab) == 84)
        return (84);
    tab[ln - 1] -= mtch;
    return (print_input(mtch, ln, nb_l, tab));
}

int start_game(char *nb_lines, char *max_sticks)
{
    int nb_l = my_getnbr(nb_lines);
    int max_s = my_getnbr(max_sticks);
    int *tab = do_my_tab(nb_l);
    int temp = 0;

    if (nb_l <= 1 || max_s < 1 || nb_l > 99)
        return (84);
    print_tab(nb_l, nb_l * 2 - 1, tab);
    while (how_many_sticks(nb_l, tab, nb_l * 2 - 1) != 0) {
        write(1, "\nYour turn:\n", 12);
        do {
            temp = check_input(nb_l, max_s, tab);
            if (temp == -1)
                return (0);
        } while (temp != 0);
        if (how_many_sticks(nb_l, tab, nb_l * 2 - 1) == 0)
            return (who_won(nb_l, tab, 2));
        turn_of_ai(tab, nb_l, max_s);
        if (how_many_sticks(nb_l, tab, nb_l * 2 - 1) == 0)
            return (who_won(nb_l, tab, 1));
    }
}

int main(int ac, char **av)
{
    if (ac != 3) {
        write(2, "Number of args invalide\n", 24);
        return (84);
    }
    return (start_game(av[1], av[2]));
}