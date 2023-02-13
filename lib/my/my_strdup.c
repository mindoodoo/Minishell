/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** .
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *cp = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    for (i ; src[i] != '\0'; i++)
        cp[i] = src[i];
    cp[i] = '\0';
    return (cp);
}