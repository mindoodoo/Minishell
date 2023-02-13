/*
** EPITECH PROJECT, 2021
** mysh.c
** File description:
** .
*/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "my.h"
#include "parsing.h"
#include "mysh.h"

char **run_line(char **envp, char *line)
{
    char **argv = av_parser(line);

    if ((argv[0][0] == '.' && argv[0][1] == '/') || argv[0][0] == '/') {
        exec_binary(argv[0], envp, argv);
        return envp;
    } else {
        return execute_command(argv, envp);
    }
}

char **handle_separators(char **envp, char *line)
{
    char **output = envp;
    char **separated_line = my_str_to_word_array(line, ';');

    for (int i = 0; separated_line[i]; i++)
        output = run_line(output, separated_line[i]);
    return output;
}

void main_loop(char **envp)
{
    int running = 1;
    int line_size = 0;
    char *line = NULL;
    size_t len = 0;

    char **new_env = copy_env(envp);

    while (running) {
        my_putstr("&>");
        line_size = getline(&line, &len, stdin);
        if (line_size == -1)
            break;
        if (line[0] == '\n')
            continue;
        line = parse_str(line, "\n")[0];
        if (!my_strcmp(line, "exit")) {
            my_putstr("exit\n");
            exit(0);
        }
        new_env = handle_separators(new_env, line);
    }
}

int main(int ac, char **av, char **envp)
{
    set_sig_handlers();
    main_loop(envp);
    return 0;
}