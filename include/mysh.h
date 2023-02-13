/*
** EPITECH PROJECT, 2021
** mysh.h
** File description:
** .
*/

#ifndef MYSH_H
#define MYSH_H

char **execute_command(char **argv, char **envp);
int exec_command(char *path, char *binary, char **envp, char **argv);
int exec_binary(char *binary, char **envp, char **argv);
void set_sig_handlers(void);
void check_segfault(int status);
char **env(char **argv, char **envp);
char **check_builtins(char **argv, char **envp);
char *search_env(char **envp, char *key);
char **cd(char **argv, char **envp);
char **copy_env(char **envp);
char **set_env(char **argv, char **envp);
int get_var_index(char **envp, char *var);
char **un_setenv(char **argv, char **envp);
char **add_value(char **argv, char **envp);

typedef struct function_ptr_s {
    char *command;
    char **(*ptr)(char **, char **);
} function_ptr_t;

#endif