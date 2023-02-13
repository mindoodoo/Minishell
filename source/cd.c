/*
** EPITECH PROJECT, 2021
** cd.c
** File description:
** .
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "mysh.h"
#include "my.h"

char **change_dir_wp(char *path, char **envp)
{
    char **argv = malloc(sizeof(char *) * 4);
    char **output = envp;

    argv[0] = my_strdup("setenv");
    argv[1] = my_strdup("OLDPWD");
    argv[2] = search_env(output, "PWD");
    argv[3] = NULL;
    output = add_value(argv, output);
    free(argv[1]);
    free(argv[2]);
    argv[1] = my_strdup("PWD");
    argv[2] = my_strdup(path);
    output = add_value(argv, output);
    free_char_table(argv);
    chdir(path);
    return output;
}

int check_cd_path(char *path)
{
    struct stat sb;

    if (stat(path, &sb) == -1) {
        my_putstr(path);
        my_putstr(": No such file or directory.\n");
        return 1;
    } else if (!S_ISDIR(sb.st_mode)) {
        my_putstr(path);
        my_putstr(": Not a directory\n");
        return 1;
    }
    return 0;
}

char **cd(char **argv, char **envp)
{
    int argc = table_len(argv);
    char *path_arg = NULL;
    char **output = envp;
    char *old_pwd = NULL;

    if (argc == 1) {
        path_arg = search_env(output, "HOME");
        output = change_dir_wp(path_arg, output);
    }
    switch (argc) {
        case 1:
            path_arg = search_env(output, "HOME");
            output = change_dir_wp(path_arg, output);
            break;
        case 2:
            if (!my_strcmp("-", argv[1])) {
                old_pwd = search_env(output, "OLDPWD");
                output = change_dir_wp(old_pwd, output);
                free(old_pwd);
                break;
            }
            if (check_cd_path(argv[1]))
                break;
            output = change_dir_wp(argv[1], output);
            break;
        default:
            my_putstr("cd: Too many arguments.\n");
            break;
    }
    return output;
}