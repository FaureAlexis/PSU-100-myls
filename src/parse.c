/*
** EPITECH PROJECT, 2021
** parse.c
** File description:
** C source file for B-PSU-100-BDX-1-1-myls-alexis.faure
*/

#include <stdlib.h>
#include "../include/ls.h"

char **parse_params(char **av)
{
    char **params = malloc(sizeof(char *) * my_arrlen(av) + 1);
    int x = 0;
    for (int i = 1; av[i] != NULL; i += 1) {
        if (av[i][0] == '-') {
            params[x] = av[i];
            x += 1;
        }
    }
    return params;
}

char **parse_path(char **av)
{
    char **path = malloc(sizeof(char *) * my_arrlen(av) + 1);
    int x = 0;
    for (int i = 1; av[i] != NULL; i += 1) {
        if (av[i][0] != '-') {
            path[x] = av[i];
            x += 1;
        }
    }
    if (path[0] == NULL)
        path[0] = ".";
    return path;
}

char *build_path(char *path, char *file_name)
{
    if (path[0] == '.') {
        char *dimitry = malloc(1 + my_strlen(file_name));
        return my_strcpy(dimitry, file_name);
    }
    int i = 0;
    int size = (my_strlen(path) + my_strlen(file_name) + 3);
    char *new_path = malloc(sizeof(char) * size);

    for (i; path[i]; i += 1)
        new_path[i] = path[i];
    if (new_path[i - 1] != '/') {
        new_path[i] = '/';
        i += 1;
    }
    int s = i;
    for (i = 0; file_name[i]; i += 1)
        new_path[s + i] = file_name[i];
    s += i;
    new_path[s + 1] = '\0';
    return new_path;
}