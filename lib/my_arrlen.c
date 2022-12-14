/*
** EPITECH PROJECT, 2021
** my_arrlen.c
** File description:
** C source file for B-PSU-100-BDX-1-1-myls-alexis.faure
*/

#include "../include/ls.h"
#include <stdlib.h>

int my_arrlen(char **arr)
{
    int i = 0;
    while (arr[i] != NULL) {
        i += 1;
    }
    return i;
}

void my_put_letsgoo(char *str)
{
    for (int i = 0; str[i] != 0; i += 1) {
        if (str[i] >= 32 && str[i] <= 127)
            my_putchar(str[i]);
    }
}

void my_print_array(char **arr)
{
    for (int i = 0; arr[i] != NULL; i += 1) {
        my_put_letsgoo(arr[i]);
        my_putchar(' ');
    }
}

char *my_arr_to_str(char **arr)
{
    int i = 0;
    int c = 0;
    char *str = malloc(sizeof(char *) * (my_arrlen(arr) + 1));
    str[0] = 0;
    while (arr[i] != NULL) {
        c += my_strlen(arr[i]);
        str = my_strcat(str, arr[i]);
        i += 1;
    }
    str[c + 1] = 0;
    return str;
}
