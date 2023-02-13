/*
** EPITECH PROJECT, 2021
** setenv.c
** File description:
** .
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int setenv_error(char **argv)
{
    if (argv[1][0] < 'A' || (argv[1][0] > 'Z' && argv[1][0] < 'a') ||
        argv[1][0] > 'z') {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    if (!my_str_isalpha(argv[1])) {
        my_putstr("setenv: Variable name must contain");
        my_putstr(" alphanumeric characters\n");
        return 1;
    }
    return 0;
}

int get_var_index(char **envp, char *var)
{
    int var_len = my_strlen(var);

    for (int i = 0; envp[i]; i++)
        if (!my_strncmp(envp[i], var, var_len))
            return i;
    return -1;
}

char **add_variable(char **argv, char **envp)
{
    int var_index;
    char *appended = NULL;
    char **output = NULL;

    if (setenv_error(argv))
        return envp;
    if ((var_index = get_var_index(envp, argv[1])) != -1)
        return envp;
    else {
        appended = my_strcat(argv[1], "=");
        output = append_str(envp, appended);
        free(appended);
        free_char_table(envp);
    }
    return output;
}

char **add_value(char **argv, char **envp)
{
    int index = -1;
    char *temp = NULL;
    char *temp2 = NULL;
    char **output = envp;

    if ((index = get_var_index(envp, argv[1])) != -1) {
        free(envp[index]);
        temp = my_strcat(argv[1], "=");
        envp[index] = my_strcat(temp, argv[2]);
        free(temp);
    } else {
        temp = my_strcat(argv[1], "=");
        temp2 = my_strcat(temp, argv[2]);
        output = append_str(envp, temp2);
        free_char_table(envp);
        free(temp);
        free(temp2);
    }
    return output;
}

char **set_env(char **argv, char **envp)
{
    int length = 0;

    for (length = 0; argv[length]; length++);
    if (length > 3)
        my_putstr("setenv: Too many arguments\n");
    switch (length) {
        case 1:
            return env(argv, envp);
        case 2:
            return add_variable(argv, envp);
        case 3:
            return add_value(argv, envp);
    }
}