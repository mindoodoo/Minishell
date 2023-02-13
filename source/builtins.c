/*
** EPITECH PROJECT, 2021
** builtins.c
** File description:
** .
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

char **check_builtins(char **argv, char **envp)
{
    function_ptr_t jump_table[] = {
        {"env", &env},
        {"cd", &cd},
        {"setenv", &set_env},
        {"unsetenv", &un_setenv},
        {NULL, NULL},
    };

    for (int i = 0; jump_table[i].command != NULL; i++)
        if (!my_strcmp(jump_table[i].command, argv[0]))
            return jump_table[i].ptr(argv, envp);
    return NULL;
}