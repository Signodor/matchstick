/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** Get number from string
*/

#include "prototypes.h"

int my_getnbr(char const *str)
{
    int first = 0;
    long nbr = 0;
    char sign = 1;
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return (-1);
    while ((str[first] < '0' || str[first] > '9') && str[first])
        first++;
    for (int i = 0; i < first; i++)
        sign *= str[i] == '-' ? -1 : 1;
    for (int i = first; str[i] >= '0' && str[i] <= '9'; i++)
        nbr = nbr * 10 + sign * (str[i] - '0');
    return (nbr);
}
