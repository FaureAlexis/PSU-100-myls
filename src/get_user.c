/*
** EPITECH PROJECT, 2021
** get_user.c
** File description:
** C source file for B-PSU-100-BDX-1-1-myls-alexis.faure
*/

#include "../include/ls.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pwd.h>
#include <grp.h>

char *get_user(struct stat s_file)
{
    uid_t uid = (uid_t) s_file.st_uid;
    struct passwd *u;
    u = getpwuid(uid);

    return u -> pw_name;
}

char *get_grp(struct stat s_file)
{
    gid_t gid = (gid_t) s_file.st_gid;
    struct group *g;
    g = getgrgid(gid);

    return g -> gr_name;
}