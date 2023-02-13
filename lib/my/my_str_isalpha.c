/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** .
*/

int my_str_isalpha(char const *str)
{
    int str_len = my_strlen(str);

    for (int i = 0; i < str_len; i++)
        if (!(str[i] >= 'A' && str[i] <= 'Z') &&
        !(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= '0' && str[i] <= '9'))
            return 0;
    return 1;
}
