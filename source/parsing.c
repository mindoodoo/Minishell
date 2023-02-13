/*
** EPITECH PROJECT, 2021
** parsing.c
** File description:
** .
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char **parse_str(char *str, char *sep)
{
    char **output = NULL;
    char *leftover = my_strdup(str);
    char *token = NULL;
    int n_tok = 0;

    for (n_tok = 0; (token = strtok_r(leftover, sep, &leftover)); n_tok++);
    leftover = my_strdup(str);
    output = malloc(sizeof(char *) * (n_tok + 1));
    output[n_tok] = NULL;
    for (int i = 0; (token = strtok_r(leftover, sep, &leftover)); i++)
        output[i] = my_strdup(token);
    return output;
}

char **insert_in_table(char **output, int *counter, char *first_parse,
    int has_quotes)
{
    char **second_parse;

    if (has_quotes) {
        output[*counter] = my_strdup(first_parse);
        (*counter)++;
    } else {
        if (my_strlen(first_parse) == 1 && first_parse[0] == ' ')
            return output;
        second_parse = parse_str(first_parse, " \t");
        for (int i = 0; second_parse[i]; i++) {
            output[*counter] = my_strdup(second_parse[i]);
            (*counter)++;
        }
    }
    return output;
}

char *check_consecutive_quotes(char *str)
{
    char *output = malloc(sizeof(char) * (my_strlen(str) + 1));
    int j = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == '\"' && str[i + 1] == '\"')
            i++;
        else {
            output[j] = str[i];
            j++;
        }
    }
    output[j] = '\0';
    return output;
}

char **av_parser(char *str)
{
    int mod_res = str[0] == '\"' ? 0 : 1;
    int counter = 0;
    char **output = malloc(sizeof(char *) * my_strlen(str));
    char **first_parse;

    str = check_consecutive_quotes(str);
    first_parse = parse_str(str, "\"");
    for (int i = 0; first_parse[i]; i++) {
        if (i % 2 == mod_res)
            insert_in_table(output, &counter, first_parse[i], 1);
        else
            insert_in_table(output, &counter, first_parse[i], 0);
    }
    output[counter] = NULL;
    return output;
}