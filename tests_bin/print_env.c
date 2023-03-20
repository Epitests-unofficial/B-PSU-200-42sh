/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** print_env
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av, char **env)
{
    char *key;
    int res = 0;

    for (int i = 0; env[i]; i++) {
        if (ac == 1) {
            printf("%s\n", env[i]);
            res = 1;
            continue;
        }
        key = strdup(env[i]);
        strtok(env[i], "=");
        if (ac == 2 && strcmp(av[1], env[i]) == 0) {
            printf("%s\n", key);
            res = 1;
            continue;
        }
        if (ac > 2) {
            printf("printenv: Too many arguments.\n");
            return 84;
        }
    }
    if (res == 0) {
        printf("printenv: Variable not found.\n");
        return 84;
    }
    return 0;
}
