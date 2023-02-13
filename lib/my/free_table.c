/*
** EPITECH PROJECT, 2021
** free_table.c
** File description:
** .
*/

void free_table(char **table)
{
    for (int i = 0; table[i]; i++)
        free(table[i]);
    free(table);
}