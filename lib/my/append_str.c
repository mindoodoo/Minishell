/*
** EPITECH PROJECT, 2020
** append_str.c
** File description:
** .
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
void free_table(char **table);

char **append_str(char **table, char *string)
{
    int length = 0;
    char **output = NULL;

    while (table[length])
        length++;
    output = malloc(sizeof(char *) * (length + 2));
    for (int i = 0; i < length; i++)
        output[i] = my_strdup(table[i]);
    output[length] = my_strdup(string);
    output[length + 1] = NULL;
    return output;
}