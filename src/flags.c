/*
** EPITECH PROJECT, 2021
** flags.c
** File description:
** C source file for B-PSU-100-BDX-1-1-myls-alexis.faure
*/

#include "../include/ls.h"
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

void display_block(char *path)
{
    int c = 0;
    DIR *op = opendir(path);
    struct dirent *stream;
    while ((stream = readdir(op)) != NULL) {
        if (stream -> d_name[0] != '.') {
            struct stat s_total;
            char *n_path = build_path(path, stream -> d_name);
            stat(n_path, &s_total);
            c += s_total.st_blocks;
            free(n_path);
        }
    }
    c /= 2;
    my_putstr("total ");
    my_put_nbr(c);
    my_putchar('\n');
}

void l_flag(char *path)
{
    display_block(path);
    DIR *op = opendir(path);
    struct dirent *stream;
    while ((stream = readdir(op)) != NULL) {
        if (stream -> d_name[0] != '.') {
            get_data(stream, path);
        }
    }
}

void recursive_flag(char *path)
{
    DIR *op = opendir(path);
    struct dirent *stream;
    while ((stream = readdir(op)) != NULL) {
        if (stream -> d_name[0] != '.') {
            my_recursive(stream, path);
        }
    }
}

void d_flag(char *path)
{
    DIR *op = opendir(path);
    struct dirent *stream;
    while ((stream = readdir(op)) != NULL) {
        if (stream -> d_name[0] != '.' && stream -> d_type == DT_DIR) {
            my_putstr(stream -> d_name);
            my_putchar(' ');
        }
    }
}