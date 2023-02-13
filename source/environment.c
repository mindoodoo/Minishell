/*
** EPITECH PROJECT, 2021
** environment.c
** File description:
** .
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"
#include "parsing.h"

char **env(char **argv, char **envp)
{
    for (int i = 0; envp[i]; i++) {
        my_putstr(envp[i]);
        my_putchar('\n');
    }
    return envp;
}

char *search_env(char **envp, char *key)
{
    char *output = NULL;
    char **table = NULL;

    for (int i = 1; envp[i]; i++) {
        table = my_str_to_word_array(envp[i], '=');
        if (!my_strcmp(key, table[0]))
            if (table[1])
                output = my_strdup(table[1]);
        free_char_table(table);
    }
    return output;
}

char **copy_env(char **envp)
{
    char **output = malloc(sizeof(char *) * (table_len(envp) + 1));

    for (int i = 0; envp[i]; i++)
        output[i] = my_strdup(envp[i]);
    output[table_len(envp)] = NULL;
    return output;
}

void remove_var(int var_index, char **envp)
{
    free(envp[var_index]);
    for (int i = var_index; envp[i]; i++)
        envp[i] = envp[i + 1];
}

char **un_setenv(char **argv, char **envp)
{
    int index = -1;

    if (!argv[1]) {
        my_putstr("unsetenv: Too few arguments.\n");
        return envp;
    }
    for (int i = 1; argv[i]; i++) {
        if ((index = get_var_index(envp, argv[i])) != -1)
            remove_var(index, envp);
    }
    return envp;
}