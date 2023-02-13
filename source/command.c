/*
** EPITECH PROJECT, 2021
** command.c
** File description:
** .
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "my.h"
#include "parsing.h"
#include "mysh.h"

int find_path(char *path, char *target)
{
    DIR *directory = opendir(path);
    struct dirent *entry = NULL;

    while ((entry = readdir(directory))) {
        if (!my_strcmp(entry->d_name, target))
            return 1;
    }
    return 0;
}

char **check_path_found(int path_found, char **argv, char **envp)
{
    if (!path_found) {
        my_putstr(argv[0]);
        my_putstr(": Command not found.\n");
    }
    return envp;
}

char **execute_command(char **argv, char **envp)
{
    char **paths = parse_path(envp);
    char **output_envp = NULL;
    int stat_return = 0;
    struct stat sb;
    int path_found = 0;

    if ((output_envp = check_builtins(argv, envp)))
        return output_envp;
    for (int i = 0; paths[i]; i++) {
        stat_return = stat(paths[i], &sb);
        if (S_ISDIR(sb.st_mode) && stat_return != -1) {
            path_found = find_path(paths[i], argv[0]);
            if (!path_found)
                continue;
            else {
                exec_command(paths[i], argv[0], envp, argv);
                break;
            }
        }
    }
    return check_path_found(path_found, argv, envp);
}