#include "../pipex.h"

int count_sigle_quotes(char *str, char c)
{
    int count;
    int i;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] == c)
            count++;
        i++;
    }
    return (count);
}
char **filter_array(char **command)
{
    char **new_array;

    new_array = ft_calloc(4, sizeof(char *));
    if (!new_array)
        return (NULL);
    new_array[0] = command[0];
    new_array[1] = command[1];
    new_array[2] = command[3];
    return (new_array);
}

char **check_commands(char **av)
{
    int count;
    char **command_split;
    char **new_array;

    count = count_sigle_quotes(*av, '\'');
    if (count == 2)
    {
        command_split = ft_split(*av, '\'');
        command_split[0] = ft_strtrim(command_split[0], " ");
        command_split[2] = NULL;
        return (command_split);
    }
    else if (count == 4)
    {
        command_split = ft_split(*av, '\'');
        command_split[0] = ft_strtrim(command_split[0], " ");
        new_array = filter_array(command_split);
        ft_free_all(command_split, NULL);
        return (new_array);
    }
    else
    {
        command_split = ft_split(*av, ' ');
        return (command_split);
    }
}
