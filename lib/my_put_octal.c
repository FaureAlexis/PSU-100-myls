/*
** EPITECH PROJECT, 2021
** my_put_octal.c
** File description:
** C source file for B-PSU-100-BDX-1-1-myprintf-alexis.faure
*/

#include <stdlib.h>

int *my_put_octal(unsigned int nbr)
{
    int *res = malloc(sizeof(unsigned int) * 8);
    int t = 0;
    for (int i = 1; nbr != 0; i += 1) {
        res[i] = nbr % 8;
        nbr = nbr / 8;
        t += 1;
    }
    if (t < 7) {
        for (int i = 0; t != 6; i += 1) {
            res[t + 1] = 0;
            t += 1;
        }
    }
    t -= 1;
    return res;
}
