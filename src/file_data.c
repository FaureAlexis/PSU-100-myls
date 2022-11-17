/*
** EPITECH PROJECT, 2021
** file_data.c
** File description:
** C source file for B-PSU-100-BDX-1-1-myls-alexis.faure
*/

#include "../include/ls.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>

char *convert_perm_nb(int i, int j, char **perms_tab, char *perms)
{
    switch (perms[i]) {
        case '7': perms_tab[j] = "rwx\0";
            break;
        case '6': perms_tab[j] = "rw-\0";
            break;
        case '5': perms_tab[j] = "r-x\0";
            break;
        case '4': perms_tab[j] = "r--\0";
            break;
        case '3': perms_tab[j] = "-wx\0";
            break;
        case '2': perms_tab[j] = "-w-\0";
            break;
        case '1': perms_tab[j] = "--x\0";
            break;
        default:
            perms_tab[j] = "---\0";
            break;
    }
    return perms_tab[j];
}

char **convert_permissions(char *perms)
{
    char **perms_tab = malloc(sizeof(char *) * 7);

    switch (perms[0]) {
        case '0': perms_tab[0] = "d";
            break;
        default : perms_tab[0] = "-";
            break;
    }
    int i = 3;
    int j = 1;
    while (i != 6) {
        perms_tab[j] = convert_perm_nb(i, j, perms_tab, perms);
        i += 1;
        j += 1;
    }
    perms_tab[j] = ".";
    perms_tab[j + 1] = NULL;
    free(perms);
    return perms_tab;
}

char *get_permissions(struct stat s_file)
{
    char *permissions = malloc(sizeof(char) * 12);
    int j = 0;

    int *oct = my_put_octal(s_file.st_mode);
    for (int i = 1; i < 7; i += 1) {
        permissions[j] = (char) oct[i] + 48;
        j += 1;
    }
    permissions[j] = '\0';
    my_putchar(' ');
    char *res = my_revstr(permissions);
    char **p = convert_permissions(res);
    res = my_arr_to_str(p);
    return res;
}

char *get_data(struct dirent *stream, char *path)
{
    if (stream->d_name[0] != '.') {
        struct stat s_file;
        char **line = malloc(sizeof(char *) * 10);
        char *n_path = build_path(path, stream->d_name);
        stat(n_path, &s_file);
        line[0] = get_permissions(s_file);
        line[1] = return_hardlink(s_file);
        line[2] = get_user(s_file);
        line[3] = get_grp(s_file);
        line[4] = get_size(s_file);
        line[5] = get_time(s_file);
        line[6] = NULL;
        my_print_array(line);
        my_putstr(stream->d_name);
        my_putchar('\n');
        free(n_path);
        return stream->d_name;
    }
}
