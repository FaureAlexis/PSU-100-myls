/*
** EPITECH PROJECT, 2021
** ls.h
** File description:
** C source file for B-PSU-100-BDX-1-1-myls-alexis.faure
*/

#ifndef B_PSU_100_BDX_1_1_MYLS_ALEXIS_FAURE_LS_H
#define B_PSU_100_BDX_1_1_MYLS_ALEXIS_FAURE_LS_H

#define COLOR_BLUE    "\x1b[34m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_END     "\x1b[0m"
#include <dirent.h>
#include <sys/stat.h>

char *my_strcat(char *dest, char *src);

void my_putstr(char *str);

int my_put_nbr(int nb);

char *my_strcpy(char *dest, char *src);

void my_putchar(char c);

int my_strlen(char *str);

int my_arrlen(char **arr);

char *my_revstr(char *str);

void my_print_array(char **ar);

char **parse_params(char **data);

char **parse_path(char **data);

char *build_path(char *path, char *filename);

int ls_complex(char **params, char **path);

char *get_data(struct dirent *stream, char *path);

int *my_put_octal(unsigned int nbr);

char *my_arr_to_str(char **);

char *get_user(struct stat s_file);

char *get_grp(struct stat s_file);

char *return_hardlink(struct stat s_file);

int my_ls(char *path);

void display_color(struct dirent *stream, char *path);

void d_flag(char *path);

void l_flag(char *path);

char *get_size(struct stat s_file);

char *get_time(struct stat s_file);

void recursive_flag(char *path);

void my_recursive(struct dirent *stream, char *path);

#endif
