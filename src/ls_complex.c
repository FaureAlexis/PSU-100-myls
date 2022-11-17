/*
** EPITECH PROJECT, 2021
** ls_complex.c
** File description:
** C source file for B-PSU-100-BDX-1-1-myls-alexis.faure
*/

#include "../include/ls.h"
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

void exec_flag(char flag, char *path)
{
    switch (flag) {
        case 'l':   l_flag(path);
            break;
        case 'R': my_putstr(path);
            my_putstr(":\n");
            my_ls(path);
            my_putstr("\n\n");
            recursive_flag(path);
            break;
        case 'd':   d_flag(path);
            break;
        default:    my_ls(path);
            break;
    }
}

void get_flags(char **params, char *path)
{
    int p_nb = my_arrlen(params);
    if (p_nb == 0) my_ls(path);
    int i = 0;
    while (i < p_nb) {
        for (int j = 1; params[i][j] != 0; j += 1) {
            exec_flag(params[i][j], path);
        }
        i += 1;
    }
}

int ls_complex(char **params, char **path)
{
    int p_nb = my_arrlen(path);
    if (p_nb == 1) {
        DIR *dir = opendir(path[0]);
        if (dir == NULL) return 84;
        get_flags(params, path[0]);
        return 0;
    }

    for (int i = 0; i != p_nb; i += 1) {
        DIR *dir = opendir(path[i]);
        if (dir == NULL) return 84;
        my_putstr(path[i]);
        my_putstr(":\n");
        get_flags(params, path[i]);
        my_putstr("\n\n");
    }
    return 0;
}
