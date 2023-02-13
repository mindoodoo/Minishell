/*
** EPITECH PROJECT, 2021
** signals.c
** File description:
** .
*/

#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include "mysh.h"
#include "my.h"

void handle_interrupt(int sig)
{
    my_putchar('\n');
}

void set_sig_handlers(void)
{
    signal(SIGINT, handle_interrupt);
}

void check_segfault(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) != 2) {
            my_putstr(strsignal(WTERMSIG(status)));
            my_putchar('\n');
        }
    }
}