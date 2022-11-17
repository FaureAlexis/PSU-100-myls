/*
** EPITECH PROJECT, 2021
** my_ls.c  display_color(stream, path);
** File description:
** C source file for B-PSU-100-BDX-1-1-myls-alexis.faure
*/

#include "../include/ls.h"
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>

void display(struct dirent *stream, char *path)
{
    my_putstr(stream -> d_name);
    my_putchar(' ');
}

int my_ls(char *path)
{
    DIR *op = opendir(path);
    if (op == NULL) return 84;
    struct dirent *stream;
    while ((stream = readdir(op)) != NULL) {
        if (stream -> d_name[0] != '.') {
            display(stream, path);
        }
    }
    return 0;
}

int start(int ac, char **av)
{
    int code = 0;
    if (ac > 1) {
        char **params = parse_params(av);
        char **path = parse_path(av);
        if (path[0] == NULL)
            path[0] = ".";
        code = ls_complex(params, path);
        free(params);
        free(path);
    } else if (ac == 1) {
        code = my_ls(".");
    }
    if (code == 84) {
        perror("Error");
    }
    return code;
}
