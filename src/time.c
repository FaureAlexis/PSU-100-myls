/*
** EPITECH PROJECT, 2021
** time.c
** File description:
** C source file for B-PSU-100-BDX-1-1-myls-alexis.faure
*/

#include "../include/ls.h"
#include <time.h>
#include <sys/stat.h>
#include <stdlib.h>

char *get_time(struct stat s_file)
{
    struct timespec time = s_file.st_mtim;
    time_t unix_timestamp = time.tv_sec;
    char *c_res = ctime(&unix_timestamp);
    char *res = malloc(13);
    int i = 4;
    int x = 0;

    while (i != 16) {
        res[x] = c_res[i];
        x += 1;
        i += 1;
    }
    res[x] = '\0';
    return res;
}
