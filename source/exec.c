/*
** EPITECH PROJECT, 2021
** exec.c
** File description:
** .
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "my.h"

int exec_command(char *path, char *binary, char **envp, char **argv)
{
    char *full_path = my_strcat(path, "/");
    pid_t pid = fork();
    int return_value;

    full_path = my_strcat(full_path, binary);
    if (!pid) {
        return_value = execve(full_path, argv, envp);
        if (return_value == -1)
            if (errno == EACCES) {
                my_putstr(binary);
                my_putstr(": Permission denied.\n");
            }
    } else
        waitpid(pid, NULL, 0);
    return 0;
}