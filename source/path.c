/*
** EPITECH PROJECT, 2021
** path.c
** File description:
** .
*/

#include <stdlib.h>
#include "my.h"
#include "parsing.h"

int get_path_index(char **envp)
{
    for (int i = 0; envp[i]; i++) {
        if (!my_strncmp(envp[i], "PATH", 4))
            return i;
    }
    return -1;
}

char **parse_path(char **envp)
{
    char *path = envp[get_path_index(envp)];
    char **output;

    path = my_strdup(&path[5]);
    output = parse_str(path, ":");
    free(path);
    return output;
}