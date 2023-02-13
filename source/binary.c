/*
** EPITECH PROJECT, 2021
** binary.c
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
#include "mysh.h"

int exec_binary(char *binary, char **envp, char **argv)
{
    int return_value = 0;
    pid_t pid = fork();

    if (!pid) {
        return_value = execve(binary, argv, envp);
        if (return_value == -1) {
            if (errno == EACCES) {
                my_putstr(binary);
                my_putstr(": Permission denied.\n");
            } else {
                my_putstr(binary);
                my_putstr(": Command not found.\n");
            }
            exit(1);
        }
    }
    else {
        waitpid(pid, &return_value, 0);
        check_segfault(return_value);
    }
    return 0;
}