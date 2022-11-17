/*
** EPITECH PROJECT, 2021
** color.c
** File description:
** C source file for B-PSU-100-BDX-1-1-myls-alexis.faure
*/

#include "../include/ls.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_exec(struct dirent *stream, char *path)
{
    struct stat s_info;
    path = build_path(path, stream->d_name);
    stat(path, &s_info);
    free(path);
    if ((s_info.st_mode & S_IXUSR) &&
        (s_info.st_mode & S_IXGRP) && (s_info.st_mode & S_IXOTH)) {
        return true;
    }
    return false;
}

void display_color(struct dirent *stream, char *path)
{
    if (stream -> d_type == DT_DIR) {
        my_putstr(COLOR_BLUE);
        my_putstr(stream->d_name);
        my_putstr(COLOR_END);
        my_putchar(' ');
    } else {
        if (is_exec(stream, path)) {
            my_putstr(COLOR_GREEN);
            my_putstr(stream->d_name);
            my_putstr(COLOR_END);
            my_putchar(' ');
        } else {
            my_putstr(stream -> d_name);
            my_putchar(' ');
        }
    }
}