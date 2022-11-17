/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** reverse a string
*/

static int my_strlenght(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count += 1;
    }
    return count;
}

char *my_revstr(char *str)
{
    int a = 0;
    int b;
    char c;

    b = my_strlenght(str) - 1;
    while (a < b) {
        c = str[b];
        str[b] = str[a];
        str[a] = c;
        a += 1;
        b -= 1;
    }
    return str;
}
