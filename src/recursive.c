/*
** EPITECH PROJECT, 2021
** recursive.c
** File description:
** C source file for B-PSU-100-BDX-1-1-myls-alexis.faure
*/

#include "../include/ls.h"
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>

void my_recursive(struct dirent *stream, char *path)
{
    if (stream -> d_type == DT_DIR) {

        char *n_path = build_path(path, stream -> d_name);
        my_putstr(n_path);
        my_putstr(":\n");
        my_ls(n_path);
        my_putstr("\n\n");
        recursive_flag(n_path);
    }
}
