/*
** EPITECH PROJECT, 2021
** data.c
** File description:
** C source file for B-PSU-100-BDX-1-1-myls-alexis.faure
*/

#include "../include/ls.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>

char *my_itoa(int nb)
{
    int nb_clone = nb;
    int c = 0;

    for (c; nb_clone > 0; c += 1)       nb_clone /= 10;
    char *res = malloc(c + 1);
    for (int j = 0; j != c; j += 1)         res[j] = ' ';
    res[c] = '\0';
    for (int i = c; i > 0; i -= 1) {
        res[i] = (char) (nb % 10) + 48;
        nb /= 10;
    }
    res[c + 1] = '\0';
    return res;
}

char *return_hardlink(struct stat s_file)
{
    unsigned int nb = s_file.st_nlink;
    return my_itoa(nb);
}

char *get_size(struct stat s_file)
{
    int size = s_file.st_size;
    if (size > 9){
        char *str = my_itoa(size);
        return str;
    }
    else {
        char *str = malloc(4);
        for (int i = 0; i != 3; i += 1) str[i] = ' ';
        str[3] = (char) size + 48;
        str[4] = '\0';
        return str;
    }
}
