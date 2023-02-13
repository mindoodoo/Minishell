/*
** EPITECH PROJECT, 2021
** free_char_table.c
** File description:
** .
*/

#include <stdlib.h>

void free_char_table(char **pointer)
{
    for (int i = 0; pointer[i]; i++)
        free(pointer[i]);
    free(pointer);
}

int table_len(char **table)
{
    int len = 0;

    while (table[len])
        len++;
    return len;
}